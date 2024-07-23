/*#include <stdio.h>
#include <string.h>
int main(int arg, char *argv[]){

for (int i=0;argv[1][i]!='\0';i++){
   if( argv[1][i]< '0'|| argv[1][i]>'9'){
    printf("failed\n");
    return 1;
   }
}
for (int i = 0; argv[1][i] != '\0'; i++)
{
   if (argv[2][i] < '0' || argv[2][i] > '9')
   {
    printf("failed\n");
    return 1;
   }
}
printf("OK\n");
}*/
/*
#include <stdio.h>
#include <string.h>
int isnum(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("failed\n");
            return 0;
        }
    }
}
int main(int argc, char* argv[])
{

    if (isnum(argv[1]) && isnum(argv[2]))
    {

        printf("OK\n");
    }
}
#include <stdio.h>
#include <string.h>
int main()
{
    int var = 2;
    int arr1D[] = {1, 2, 3, 4};
    int arr2D[3][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
    };
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf("%i", arr2D[j][i]);
        }
    }
}
*/

// в матрице ищем главную и побочную диагональ
/*
#include <stdio.h>

int main()
{
    int i, j;
    int N;
    printf("Zadejte rozmer matice: ");
    scanf("%i", &N);
    int a[N][N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Zadejte element matice: ");
            scanf("%d", &a[i][j]);
        }
        putchar('\n');
    }

    for (i = N - 1; i >= 0; i--)
    {
        printf("%d ", a[i][i]);
    }
    putchar('\n');
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i][i]);
    }

    return 0;
}
*/

// ПРОВЕРЯЕТ ЕСЛИ ВО ВВЕДЕННОЙ СТРОКЕ ТОЛЬКО ЧИСЛА
/*
#include <stdio.h>
#include <string.h>
int is_number(char arr[])
{
    for (int i = 0; i < (int)strlen(arr); i++)
    {
        if ((arr[i] < '0') || (arr[i] > '9'))
        {
            printf("Neobsahuje jenom cisla !\n");
            return 0;
        }
    }
    return 0;
}
int main()
{
    char str[21];
    printf("\nEnter value : ");
    scanf("%s", str);
    if (is_number(str))
    {
        printf("Ok!Obsahuje jenom cisla\n");
    }
    return 0;
}
*/
// ИЩЕМ КАКИЕ ИЗ ДВУХ ЧИСЕЛ БОЛЬШЕ
/*
#include <stdio.h>
#include <stdlib.h> //для функции atoi
#include <string.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    else if (a == b)
    {
        printf("%d==%d", a, b);
        return 0;
    }
    return 0;
}
int main(int argc, char *argv[]) // argv- обязательно типа char, то есть строка => нам нужно преобразовать строку в инт, подключаем библиотку и спользуем функцию atoi
{
    if (argc != 3)
    {
        printf("Usage: %s errror\n", argv[0]);
        return 1;
    }

    int cislo1 = atoi(argv[1]); // преобразует строку в интеджер
    int cislo2 = atoi(argv[2]);
    if (max(cislo1, cislo2))
    {

        printf("Vetsi z nich je %i", max(cislo1, cislo2));
    }
    return 0;
}
*/
/*

НАЙТІ МІНІМУМ ИЗ ДВУХ ЧИСЕЛ

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int my_crazy_min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else if (b < a)
    {
        return b;
    }
    else if (b == a)
    {
        printf("%d==%d", a, b);
        return 0;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\n%s error\n", argv[0]);
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    if (my_crazy_min(num1, num2))
    {
        printf("%d", my_crazy_min(num1, num2));
    }
    return 0;
}
*/

// hledá první výskyt znaku v řetězci, vrací -1, pokud se znak v řetězci nevyskytuje
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int hledani_znaku(char a, char b[])
{
    for (int i = 0; i < (int)strlen(b); i++)
    {
        if (b[i] == a)
        {
            printf("We have found the sign %c in string and it has index %i", b[i], i);
            return 1;
            i++;
            break;
        }
    }

    return 0;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("error%s", argv[0]);
    }

    if (hledani_znaku(argv[1][0], argv[2]) == 0)
    {

        printf("We have not found sign %c", argv[1][0]);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isSEt(char arr[])
{
    for (int i = 0, j = 0; j < (int)strlen(arr); j++)
    {
        if (arr[i] == arr[j + 1])
        {
            printf("Neni mnozina");
            return 0;
        }
        if (j == (int)strlen(arr) - 1)
        {
            i++;
            j = i; // вместо j=i+1;
        }
        // return 1;
    }
    return 1;
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("error %s", argv[0]);
    }
    if (isSEt(argv[1]))
    {
        printf("Je mnozina");
    }
}
*/

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
