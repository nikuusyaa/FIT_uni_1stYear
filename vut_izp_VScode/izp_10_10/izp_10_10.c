
/*#include <stdio.h>
#define N 10
int main(void)
{
    int sqrs[N];
    // for (int i = 1; i <= N; i++) // tak ne!
    for (int i = 0; i < N; i++)
    { // tak ano printf("%d ", sqrs[i]);
        sqrs[i] = i * i;
        printf("%d\n", sqrs[i]);
    }
    return 0;
}*/

/*                                        \
#include <stdio.h>                        \
#define RADKY 10                          \
#define SLOUPCE 10                        \
int main()                                \
{                                         \
    int matice[RADKY][SLOUPCE];           \
    for (int r = 1; r < RADKY; r++)       \
        for (int s = 1; s < SLOUPCE; s++) \
            matice[r][s] = r * s;         \
    for (int r = 1; r < RADKY; r++)       \
    {                                     \
        for (int s = 1; s < SLOUPCE; s++) \
        {                                 \
            printf("%d ", matice[r][s]);  \
        }                                 \
        printf("\n");                     \
    }                                     \
}                                         \
*/

/*#include <stdio.h>
void zamen(int *pa, int *pb)
{
    int pom = *pa;
    *pa = *pb;
    *pb = pom;
}
int main(void)
{
    int i = 7, j = 3;
    zamen(&i, &j); // pozor,nesmí chybět & printf("i == %d, j == %d\n", i, j); return 0;
    printf("i == %d, j == %d\n", i, j);
}
*/

/*#include <stdio.h>
int count_occur_of_e()
{
    int cnt;
    int c;
    while ((c=getchar())!=EOF)
    {

            if (c == 'e'){
                cnt++;
        }

        return cnt;
    }
}

int counter_occur_of_e_from_file(char *filename){
    FILE *source_file=fopen(file)
}
int main(int argc, char **argv)
{
    // (void) argc;
    // (void) argv;
    int cnt;
    if (argc < 2)
        cnt = count_occur_of_e();
    else
        cnt = count_occur_of_e_from_file(argv[1]);
    return 0;
}*/
/*
#include <stdio.h>
    int
    main()
{
    char sen[101];
    printf("Enter value");
    scanf("%s", &sen);
    printf("\nYou wrote %s:", sen);
    return 0;
}
*/
/*
#include <stdio.h>
#include<string.h>
int main()
{
    char str[101];
    int length = 0;
    printf("Enter value :");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        length += length;
    }
    printf("The length of string is : %d", length);
}*/
/*
#include <stdio.h>
#include <string.h>
int main()
{

    char str[101];

    printf("Select a string: ");
    scanf("%s", str);
    int str_len = 0;
    while (str[str_len] != '\0')
    {
        printf("%c\n", str[str_len]);
        str_len++;
    }
    printf("String length: %d\n", str_len);
    return 0;
}*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char x[100];

    scanf("%99s", x);

    for (int i = 32; i <= 126; i++)
    {
        for (int j = 0; j < (int)strlen(x); j++)
        {
            if (i == x[j])
            {
                printf("%c ", x[j]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
*/

// Zjistěte, kolik načtený řetězec obsahuje písmen a kolik číslic.
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int symb = 0, numb = 0;
    printf("Enter string: ");
    scanf("%99s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            symb++;
        }
        else if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            symb++;
        }
        else if ((str[i] >= '0') && (str[i] <= '9'))
        {
            numb++;
        }
    }
    printf("Number of numbers is: %d \n Number of symbols is: %d ", numb, symb);
    return 0;
}*/

/*
Заменить все заглавные буквы на обычные способ 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%s", &str);
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("\n%s", str);

    return 0;
}*/
/*
 заменить все заглавные буквы на обычные способ 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%s", &str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
        printf("%c", str[i]);
    }

    return 0;
}
*/
// СПОСОБ 3 от второго отличается только тем, что мы выводим уже саму строку в конце полностью, а не по символам
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%s", &str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("%s", str);

    return 0;
}*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    scanf("%99s", &str);// когда работаем со строками и массивами, в  функции scanf амперсант не нужен
    printf("%s", str);
}*/

// КАК НАЙТИ ДЛИНУ СТРОГКИ С ПОМОЩЬЮ ФУНКЦИИ STRLEN
/*#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    // nt length;
    printf("Enter string\n");
    scanf("%99s", str);
    // length = strlen(str);
    printf("String length is:%zu", strlen(str));
}*/

// НАЙТИ СКОЛЬКО БОЛЬШИХ БУКВ, МАЛЕНЬКИХ БУКВ, ЦИФР
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int velke_pismeno, male_pismeno, cislo;
    printf("Enter value:\n");
    scanf("%99s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            male_pismeno++;
        }
        else if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            velke_pismeno++;
        }
        else if ((str[i] >= '0') && (str[i] <= '9'))
        {
            cislo++;
        }
    }
    printf("\nPocet velkych pismen= %i", velke_pismeno);
    printf("\nPocet malych pismen =%i", male_pismeno);
    printf("\nPocet cislic=%i", cislo);
}*/

// БОЛЬШАЯ БУКВА НА МАЛЕНЬКУЮ И НАОБОРОТ
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter string: \n");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            str[i] -= 32;
            printf("%c", str[i]);
        }
        else if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            str[i] += 32;
            printf("%c", str[i]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}
*/
// ВЫЯСНИТЬ СОДЕРЖАТЬСЯ ЛИ В СТРОКЕ ТОЛЬКО ЧИСЛА
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    unsigned long pocet = 0;
    printf("\nEnter string: ");
    scanf("%s", str);
    for (unsigned long i = 0; i < strlen(str); i++)
    {
        if ((str[i] < '0') || (str[i] > '9'))
        {
            printf("Obsahuje pismena");
            break;
        }
        else
        {
            pocet++;
        }
    }
    if (pocet == strlen(str))
    {
        printf("\nObsahije jenom cisla");
    }
}
*/

/*#include <stdio.h>
void r(int x)
{
    if (x)
    {
        r(--x);
        printf("%d\n", x);
    }
}
int main(void)
{
    r(5);
    return 0;
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[1][4] = {{'Praha'},
                      {'Brno'},
                      {'Bruntal'},
                      {'Bratislava'}};
    for (int i = 0; i < 4; i++)
    {
        printf("%c", arr[1][i]);
    }
}
}*/

