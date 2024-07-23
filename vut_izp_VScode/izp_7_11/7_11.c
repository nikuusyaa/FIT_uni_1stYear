/*
#include<stdio.h>
int main(){

char p;
p='c';
char* pp=&p;
*pp='a';
printf("%c",p );
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int *arr = (int*)malloc(10*sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Cant allocate memory\n");
        return 1;
    }
    for (int i=0;i<10;i++){
    *(arr+i) = 23;

    printf("%d", *(arr+i));
    }
    if (arr != NULL)
    {
        free(arr);
    }
}

#include <stdlib.h>
#include <stdio.h>
struct S1{
    int i;
    int d;
};
void init( struct S1 s1){

    if(s1 == NULL)
    {
        fprintf(stderr, "Cant allocate memory\n");
        return 1;
    }
    for (int i = 0; i < sizeof(s1); i++)
    {
        s1->d = 0;
        s1->i = 1;
        printf("s1->d =%d, s1->i=%d ", s1->d, s1->i);
    }
    if (s1 != NULL)
    {
        free(s1);
    }
}
int main(void){
    struct S1 *s1 = (struct S1 *)(malloc(sizeof(struct S1)));

    init(s1);
}
#include <stdlib.h>
#include <stdio.h>

struct S1
{
    int i;
    int d;
};

struct S1 *init(int i, int d)
{
    struct S1 *s1 = (struct S1 *)(malloc(sizeof(struct S1)));

    if (s1 == NULL)
    {
        fprintf(stderr, "Can't allocate memory\n");
        return NULL;
    }

    s1->d = d;
    s1->i = i;
   // printf("s1->d = %d, s1->i = %d\n", s1->d, s1->i);
    //free(s1);
    return s1;
}

int main(void)
{

    int i = 0;
    int d = 1;

    struct S1 *s1 = init(i, d);

    if (s1 == NULL)
    {
        return 1;
    }
    printf("s1->d = %d, s1->i = %d\n", s1->d, s1->i);
    free(s1);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

int *sum(int *arr1, int *arr2, int n)
{
    int *result = (int *)malloc(n * sizeof(int));
    if (result == NULL)
    {
        fprintf(stderr, "Can't allocate memory\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = arr1[i] + arr2[i];
    }
    return result;
}

int main(void)
{
    int n = 3;
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};

    int *result = sum(arr1, arr2, n);

    if (result == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("sum arr[%d] = %d\n", i, result[i]);
    }

    free(result);
    return 0;
}

#include <stdio.h>
int a=4, b=3;
void test(int*c){
int a=*c; printf("%d%d",a,b);
if(a>b){a=b;}
else {int b = a; printf("%d%d", a, b);}
*c=a;
}
int main(void){

int pocetit=0;
for (int num = 1; num < 11; ++num){

//printf("%d ", );
pocetit++;

}

printf("\n%d", 0%3);
}
#include<stdio.h>
unsigned fact(int n){
    if(n>1)
    return n*fact(n-1);
    else return 1;
}
int main(int argc, char **argv){
    unsigned n=strtoul(argv[1], NULL, 10);
    printf("factrorial(%d)=%d\n",n ,fact(n));

    return 0;

}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
} vector_t;

int vector_add(vector_t *vec, int value)
{
    int *new_arr = (int *)malloc((vec->size + 1) * sizeof(int));
    if (new_arr == NULL)
    {
        return 0;
    }

    for (int i = 0; i < vec->size; i++)
    {
        new_arr[i] = vec->arr[i];
    }

    free(vec->arr);

    new_arr[vec->size] = value;
    vec->arr = new_arr;
    vec->size += 1;

    return 1;
}

int vector_add_2(vector_t *vec1, vector_t *vec2) //сумма двух векторов
{
    if (vec1->size != vec2->size)
    {
        fprintf(stderr, "Vectors are different sizes\n");
        return 0;
    }

    int *sum = (int *)malloc(vec1->size * sizeof(int));
    if (sum == NULL)
    {
        return 0;
    }

    for (int i = 0; i < vec1->size; i++)
    {
        sum[i] = vec1->arr[i] + vec2->arr[i];
    }

    free(vec1->arr);
    vec1->arr = sum;

    return 1;
}
void vect_scalar(vector_t* vec, int scalar)// умножение данного вектора на скаляр
{


    for(int i=0;i<vec->size;i++){
        vec->arr[i]=vec->arr[i]*scalar;
    }

 
}

void vect_dtor(vector_t *vector)
{
    if (vector == NULL)
    {
        return;
    }
    if (vector->arr != NULL)
    {
        free(vector->arr);
    }
    free(vector);
}

vector_t *vector_ctor()
{
    vector_t *vec = (vector_t *)malloc(sizeof(vector_t));
    if (vec != NULL)
    {
        vec->arr = NULL;
        vec->size = 0;
    }
    return vec;
}

int find_substring(char *str, char *substr)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int j;
        for (j = 0; substr[j] == str[j + i]; j++)
        {
            if (substr[j + 1] == '\0')
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    vector_t *vec1 = vector_ctor();
    vec1->size = 3;
    vec1->arr = (int *)malloc(vec1->size * sizeof(int));
    vec1->arr[0] = 1; 
    vec1->arr[1] = 2; 
    vec1->arr[2] = 3; 

    vector_t *vec2 = vector_ctor();
    vec2->size = 3;
    vec2->arr = (int *)malloc(vec2->size * sizeof(int));
    vec2->arr[0] = 1;
    vec2->arr[1] = 3;
    vec2->arr[2] = 3;

    int a=2;
    vect_scalar(vec1, a);
    vector_add_2(vec1, vec2);
    for (int i = 0; i < vec1->size; i++)
    {
        printf("%d ", vec1->arr[i]);
    }

    vect_dtor(vec1);
    vect_dtor(vec2);
    char *str="Hello";
    char *sbstr='l';
    find_substring(&str, &sbstr);

    return 0;
}
// ackermanova funkce

//udelat nahrazeni substringu jinym substringem
#include <stdio.h>
int find_min(int i, int arr[], int size)
{
    int min_index = i;
    for (int j = i + 1; j < size; j++)
    {
        if (arr[j] < arr[min_index])
        {
            min_index = j;
        }
    }
    return min_index;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_index = find_min(i, arr, size);
        swap(&arr[i], &arr[min_index]);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("not sorted array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    sort(arr, size);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
// Пытаемся двигаться вперед
if (direction == leftb)
{
    if (has_top_wall(row, col))
    {

        col--; // есть
    }
    else
    {
        row++; // есть
    }
}
else if (direction == rightb)
{
    if (has_top_wall(row, col))
    {
        col++; //
    }
    else
    {
        row++;
    }
}
else if (direction == bottomb)
{
    if (has_top_wall(row, col))
    {

        row--;
    }
    else
    {
        col++;
    }
}

// Если есть проход вперед, продолжаем движение
if (!isborder(&map, row, col, direction))
{
    continue;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct Data
{
    int id;
    char *name;
} Data;

typedef struct Item
{
    struct Item *next;
    Data *data;
} Item;

typedef struct
{
    Item *first;
} List;

Data *data_ctor(int id, char *name)
{
    Data *data = malloc(sizeof(*data));
    data->id = id;
    data->name = malloc(sizeof(char) * (1 + strlen(name)));
    if (data->name == NULL)
    {
        free(data);
        return NULL;
    }
    strcpy(data->name, name);
    return data;
}

Item *item_ctor(Data *data)
{
    Item *item = malloc(sizeof(*item));
    if (item == NULL)
    {
        return NULL;
    }
    item->data = data;
    item->next = NULL; 
    return item;
}

bool empty(List *list)
{
    return list->first == NULL;
}

void add_item(List *list, Item* newitem)
{
    
        newitem->next = list->first;
        list->first = newitem;
    
}
List list_ctor()
{
    return (List){.first = NULL}; 
}

void print_data(Data *data)
{
    printf("%d %s ", data->id, data->name); 
}

void print_item(Item *item)
{
    printf("%s", item->next == NULL ? "==" : "!="); 
    print_data(item->data);
}


int list_size(List *list)
{
    int size = 0;
    Item *current = list->first;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}
void delete_first(List* list){
    if(list->first==NULL){
        return NULL;
    }
    Item*current=list->first;
    list->first = current->next;
    
}

int main()
{
    List list=list_ctor();

    

    return 0;
}
