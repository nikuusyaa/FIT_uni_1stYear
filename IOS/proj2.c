#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <memory.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_STATIONS 10
#define MAX_SKIERS 20000
#define MAX_BUS_CAPACITY 100
#define MAX_SKIER_TIME_TL 10000
#define MAX_BUS_TIME_TB 1000

struct Bus_info
{
    int current_station;
    int capacity;
    int ppl_count;
    int max_travel_time;
    sem_t one_man_inout;
};

struct Station_info
{
    int id;
    int ppl_count;
    sem_t bus_here;
};

struct SharedMemory // structure to put into shared memory
{
    struct Bus_info Bus;
    int total_ppl_count;
    int station_count;
    int A;
    FILE *fp;
    struct Station_info Stations[MAX_STATIONS + 1];
};

void *create_shared_memory(size_t size);
void bus_process(void *shm);
void skier_process(int id, int station, int breakfasttime, void *shm);
void Cleanup(void *shm);

int main(int argc, char **argv)
{
    if (argc != 6)
    {
        perror("Some arguments are missing");
        return 1;
    }

    int L = atoi(argv[1]);     // Кол-во лыжников
    int STOPS = atoi(argv[2]); // Кол-во остановок
    int K = atoi(argv[3]);     // Вместимость автобуса
    int TL = atoi(argv[4]);    // Время ожидания лыжника
    int TB = atoi(argv[5]);    // Перемещение между остановками

    // check input values
    //...

    struct SharedMemory ShMem;

    ShMem.station_count = STOPS;
    ShMem.total_ppl_count = L;
    ShMem.Bus.current_station = 0;
    ShMem.Bus.capacity = K;
    ShMem.Bus.ppl_count = 0;
    ShMem.A = 1;
    ShMem.Bus.max_travel_time = TB;
    sem_init(&ShMem.Bus.one_man_inout, 1, 0);
    ShMem.fp = fopen("proj2.out", "w");
    if (ShMem.fp == NULL)
    {
        fprintf(stderr, "Can't open proj2.out\n");
    }

    setvbuf(ShMem.fp, NULL, _IOLBF, 0);

    for (int i = 0; i <= STOPS; i++)
    {
        ShMem.Stations[i].id = i;
        ShMem.Stations[i].ppl_count = 0;
        sem_init(&ShMem.Stations[i].bus_here, 1, 0);
    }

    void *shm = create_shared_memory(sizeof(ShMem));
    memcpy(shm, &ShMem, sizeof(ShMem));

    pid_t pid = fork();
    if (pid == 0)
    {
        bus_process(shm);

        exit(0);
        return 0;
    }
    else if (pid > 0)
    {
        srand(time(NULL));

        for (int i = 1; i <= L; i++)
        {
            int station = (rand() % ShMem.station_count) + 1;
            int breakfasttime = (rand() % TL) + 1;

            pid = fork();
            if (pid == 0)
            {
                skier_process(i, station, breakfasttime, shm);

                exit(0);
                return 0;
            }
            else if (pid > 0)
            {
            }
            else
            {
                perror("L process start failed!");
                fclose(ShMem.fp);
                return 1;
            }
        }
    }
    else
    {
        perror("Bus process start failed!");
        fclose(ShMem.fp);
        return 1;
    }

    wait(NULL);

    Cleanup(shm);
    fclose(ShMem.fp);

    return 0;
}

void *create_shared_memory(size_t size)
{
    // Our memory buffer will be readable and writable:
    int protection = PROT_READ | PROT_WRITE;

    // The buffer will be shared (meaning other processes can access it), but
    // anonymous (meaning third-party processes cannot obtain an address for it),
    // so only this process and its children will be able to use it:
    int visibility = MAP_SHARED | MAP_ANONYMOUS;

    // The remaining parameters to `mmap()` are not important for this use case,
    // but the manpage for `mmap` explains their purpose.
    return mmap(NULL, size, protection, visibility, -1, 0);
}

void Cleanup(void *shm)
{
    struct SharedMemory *ShMem = (struct SharedMemory *)shm;

    sem_destroy(&ShMem->Bus.one_man_inout);

    for (int i = 0; i <= ShMem->station_count; i++)
    {
        sem_destroy(&ShMem->Stations[i].bus_here);
    }
}

void bus_process(void *shm)
{
    struct SharedMemory *ShMem = (struct SharedMemory *)shm;

    fprintf(ShMem->fp, "%d: BUS: started\n", ShMem->A++);

    srand(time(NULL));

    while (ShMem->total_ppl_count > 0)
    {
        // random time to travel to the station
        int travel_time = (rand() % ShMem->Bus.max_travel_time) + 1;
        usleep(travel_time);
        ShMem->Bus.current_station++;
        if (ShMem->Bus.current_station > ShMem->station_count)
        {
            ShMem->Bus.current_station = 0;
        }

        if (ShMem->Bus.current_station == 0)
        {
            fprintf(ShMem->fp, "%d: BUS: arrived to final\n", ShMem->A++);
        }
        else
        {
            fprintf(ShMem->fp, "%d: BUS: arrived to %d\n", ShMem->A++, ShMem->Bus.current_station);
        }

        // determine number of people to board
        int people_to_board = ShMem->Bus.capacity - ShMem->Bus.ppl_count;
        if (ShMem->Bus.current_station > 0)
        {
            if (people_to_board > ShMem->Stations[ShMem->Bus.current_station].ppl_count)
            {
                people_to_board = ShMem->Stations[ShMem->Bus.current_station].ppl_count;
            }
        }
        else
        {
            people_to_board = ShMem->Bus.ppl_count;
        }

        for (int i = 0; i < people_to_board; i++)
        {
            sem_post(&ShMem->Stations[ShMem->Bus.current_station].bus_here);
        }
        while (people_to_board > 0)
        {
            sem_wait(&ShMem->Bus.one_man_inout);
            people_to_board--;
            if (ShMem->Bus.current_station > 0)
            {
                ShMem->Bus.ppl_count++;
            }
            else
            {
                ShMem->Bus.ppl_count--;
                ShMem->total_ppl_count--;
            }
        }

        if (ShMem->Bus.current_station > 0)
        {
            fprintf(ShMem->fp, "%d: BUS: leaving %d\n", ShMem->A++, ShMem->Bus.current_station);
        }
        else
        {
            fprintf(ShMem->fp, "%d: BUS: leaving final\n", ShMem->A++);
        }
    }

    fprintf(ShMem->fp, "%d: BUS: finish\n", ShMem->A++);
}

void skier_process(int id, int station, int breakfasttime, void *shm)
{
    struct SharedMemory *ShMem = (struct SharedMemory *)shm;

    int my_station = station;
    int my_breakfast = breakfasttime;

    fprintf(ShMem->fp, "%d: L %d: started\n", ShMem->A++, id);

    usleep(my_breakfast);
    ShMem->Stations[my_station].ppl_count++;
    fprintf(ShMem->fp, "%d: L %d: arrived to %d\n", ShMem->A++, id, my_station);

    sem_wait(&ShMem->Stations[my_station].bus_here);
    // fprintf(fp, "L %d boarding (%d)...\n", id, my_station);

    ShMem->Stations[my_station].ppl_count--;
    fprintf(ShMem->fp, "%d: L %d: boarding\n", ShMem->A++, id);

    sem_post(&ShMem->Bus.one_man_inout);

    sem_wait(&ShMem->Stations[0].bus_here);
    fprintf(ShMem->fp, "%d: L %d: going to ski\n", ShMem->A++, id);

    sem_post(&ShMem->Bus.one_man_inout);
}
