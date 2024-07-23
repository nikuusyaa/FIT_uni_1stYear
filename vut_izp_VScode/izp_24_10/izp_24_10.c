/*


1. Implementujte funkci pro detekci validního data.

#include <stdio.h>
#include <stdlib.h>
struct date
{
    int year;
    int month;
    int day;
};
int if_valid_date(struct date date1)
{

    if (date1.year < 1582 || date1.year > 2500 || date1.month < 1 || date1.month > 12 || date1.day > 31 || date1.day < 1)
    {
        return 0;
    }
    if (date1.day == 31 && date1.month != 1 && date1.month != 3 && date1.month != 5 && date1.month != 7 && date1.month != 8 && date1.month != 10 && date1.month != 12)
    {
        return 0;
    }
    else if (date1.month == 2)
    {
        if (date1.day == 31 || date1.day == 30)
        {
            return 0;
        }
        else if (date1.day == 29 && (!(date1.year % 4 == 0 && date1.year % 100 != 0) || date1.year % 400 == 0))
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("error %s", argv[0]);
    }
    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);
    struct date our_data = {
        year,
        month,
        day};

    if (if_valid_date(our_data))
    {
        printf("The date is valid\n");
    }
    else
    {
        printf("The date is not valid\n");
    }
    return 0;
}
2. Implementujte funkci pro rozhodnutí, které z dvou dat je pozdeí.

#include <stdio.h>
#include <stdlib.h>

                                        struct date
{
    int day;
    int month;
    int year;
};

void bigger_date(struct date date, struct date date2)
{

    if (date.year > date2.year)
    {
        printf("The first date %i %i %i is bigger", date.day, date.month, date.year);
    }
    else if (date2.year > date.year)
    {
        printf("The second date %i %i %i is bigger", date2.day, date2.month, date2.year);
    }
    if (date.month > date2.month && date.year == date2.year)
    {
        printf("The first date %i %i %i is bigger", date.day, date.month, date.year);
    }
    else if (date2.month > date.month && date.year == date2.year)
    {
        printf("The second date %i %i %i is bigger", date2.day, date2.month, date2.year);
    }
    if (date.day > date2.day && date.year == date2.year && date.month == date2.month)
    {
        printf("The first date %i %i %i is bigger", date.day, date.month, date.year);
    }
    else if (date.day > date2.day && date.year == date2.year && date.month == date2.month)
    {
        printf("The second date %i %i %i is bigger", date2.day, date2.month, date2.year);
    }
    if (date.day == date2.day && date.year == date2.year && date.month == date2.month)
    {
        printf("Dates are equal");
    }
}

int main(int argc, char **argv)
{
    if (argc != 7)
    {
        printf("%s Error", argv[0]);
    }
    int day1 = atoi(argv[1]);
    int day2 = atoi(argv[4]);
    int month1 = atoi(argv[2]);
    int month2 = atoi(argv[5]);
    int year1 = atoi(argv[3]);
    int year2 = atoi(argv[6]);

    struct date date1 = {
        day1, month1, year1};
    struct date date2 = {
        day2, month2, year2};
    bigger_date(date1, date2);
    return 0;
}

// 2. Implementujte funkci pro rozhodnutí, které z dvou dat je dřívější.

#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

int earlier_date(struct date date00, struct date date01)
{
    if (date00.year < date01.year)
    {
        return 0;
    }
    else if (date00.year > date01.year)
    {
        return 1;
    }

    if (date00.month < date01.month)
    {
        return 0;
    }
    else if (date00.month > date01.month)
    {
        return 1;
    }

    if (date00.day < date01.day)
    {
        return 0;
    }
    else if (date00.day > date01.day)
    {
        return 1;
    }
    return 2;
}

int main(int argc, char **argv)
{
    if (argc != 7)
    {
        printf("%s Error", argv[0]);
    }
    int day1 = atoi(argv[1]);
    int day2 = atoi(argv[4]);
    int month1 = atoi(argv[2]);
    int month2 = atoi(argv[5]);
    int year1 = atoi(argv[3]);
    int year2 = atoi(argv[6]);

    struct date date1 = {
        day1, month1, year1};
    struct date date2 = {
        day2, month2, year2};
    if (earlier_date(date1, date2) == 1)
    {
        printf("The second day is earlier");
    }
    else if (earlier_date(date1, date2) == 0)
    {
        printf("The first day is earlier");
    }
    else
    {
        printf("Dates are equal");
    }
    return 0;
    }
// ЧТЕНИЕ ИЗ ФАЙЛА И ВЫВОДМ В КОМАНДНУЮ СТРОКУ
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error while opening file\n");
        return 1;
 }
  char buffer[100];
  fscanf(file, "%99[^\n]", buffer); // если хотим прочитать весь файл, то пишем так [^\n]- значит читаем все что есть в файле кроме пробелов . Нам  нужно это потому что функция fscanf будет читать пока не встретит пробел
                                    // fprintf(file, "%s\n", "beer is here");
  printf("loaded:%s", buffer);


fclose(file);
}


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error while opening file\n");
        return 1;
    }
    char buffer[100];
    while(fscanf(file, "%99[^\n]\n", buffer )==1){
        printf("%s\n", buffer);
    }
    fclose(file);
}
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int year;
    int month;
    int day;
};

int which_before(struct date data1, struct date data2)
{

    if (data1.year < data2.year)
    {
        return 1;
    }
    else if (data1.year > data2.year)
    {
        return 0;
    }
    if (data1.month < data2.month)
    {
        return 1;
    }
    else if (data1.month > data2.month)
    {
        return 0;
    }
    if (data1.day < data2.day)
    {
        return 1;
    }
    else if (data1.month > data2.month)
    {
        return 0;
    }
    return 2;
}

int main(int argc, char **argv)
{
    if (argc != 7)
    {
        printf("Error %s", argv[0]);
    }
    struct date first_date = {
        .day = atoi(argv[1]),
        .month = atoi(argv[2]),
        .year = atoi(argv[3]),
    };

    struct date second_date = {
        .day = atoi(argv[4]),
        .month = atoi(argv[5]),
        .year = atoi(argv[6]),
    };
    if (which_before(first_date, second_date) == 1)
    {
        printf("The first day is before the second");
    }
    else if (which_before(first_date, second_date) == 0)
    {
        printf("The second day is before the first");
    }
    else if (which_before(first_date, second_date) == 2)
    {
        printf("The first day equals to the second");
    }
}
*/

// pole - homogenní(jenom prvky stejneho typu)  struktura-heterogenni(ruzne prvky)
/*

#include <stdio.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}
int main(void)
{

    int a = 2;
    int b = 5;
    swap(&a, &b);
    printf("\n%i", a);
    printf("\n%i",b);
    // int *p; //указатель на интеджер
    //   p=&i;// в p вложим ходноту i;
    // printf("%i\n", i);
    // printf("%i\n", *p);
    // * přistup do paměti , & přistup do hodnoty
    // указатели нужны, чтобы менять значения переменных в функции
}


#include <stdio.h>
void div(double *a, double *b )
{
    double temp_a=*a;
    double temp_b=*b;
    double res= temp_a/temp_b;
    return res;
}
int main(void)
{

    int a = 8;
    int b = 2;


    //swap(&a, &b);
    printf("\n%i", div(&a, &b));
    //printf("\n%i", b);
}
#include <stdio.h>

void div(double *a, double *b, double *res)
{
    double temp_a = *a;
    double temp_b = *b;
    *res = temp_a / temp_b;
}

int main(void)
{
    double a = 9.0;
    double b = 3.0;
    double res ;
    div(&a, &b, &res);
    printf("\n%.3f", res);
}

*/
#include <stdio.h>

void div(double *a, double *b, double *res)
{
    double temp_a = *a;
    double temp_b = *b;
    *res = temp_a / temp_b;
}

int main(void)
{
    double a = 9.0;
    double b = 3.0;
    double res=1.0;
    div(&a, &b, &res);
    printf("\n%.3f", res);
}
