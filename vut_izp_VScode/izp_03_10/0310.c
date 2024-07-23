
/*
//программу которая считает факториал цикл while

#include <stdio.h>

int main()
{
    int i = 1;
    int a;
    int b;
    printf("Enter value \n");
    scanf("%i", &a);
    b = a;
    while (i < b)
    {
        a = a * i;
        i++;
    }
    printf("%i", a);
}*/

/*

найти факториал числа с помощью цикла for

#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter value\n");
    scanf("%i", &a);
    b = a;
    for (int i = 1; i < b; i++)
    {
        a = a * i;
    }
    printf("%i", a);
}*/

// Načtěte 3 čísla a pro každé číslo určete zda je sudé.
/*#include <stdio.h>
    int
    main()
{
    int a;
    printf("Enter values\n");
    for (int i = 1; i <= 3; i++)
    {
        scanf("%i", &a);
        if (a % 2 == 0)
        {
            printf("Je sude %i\n", a);
        }
    }
}*/
/*

Upravte předchozí příklad, ale načtěte 100 čísel.
• rozšíření: Načtěte číslo udávající počet čísel, které budete načítat a určovat jejich sudost (počet čísel není předem znám).

#include <stdio.h>
int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%i\n", i);
        }
    }
}*/

/*

Načtěte 5 čísel a vypište je v opačném pořadí.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter naumber of values of array\n");
    scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }
    for (int j = n - 1; j >=0; j--)
    {

        printf("%i", arr[j]);
    }
}
*/
/*
#include <stdio.h>
int main()
{
    int n, max, min;
    printf("Enter number of vallues of array\n");
    scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < n; i++)
        {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Minimum je %i ", min);
    printf("Maximum je %i ", max);
    return 0;
}*/

// Vytvořte program, který převede dobu uvedenou v počtu hodin a minut na sekundy.

/*#include <stdio.h>
int main()
{
    int hodiny, minuty, sekundy;
    printf("Enter hours and minutes\n");
    scanf("%i", &hodiny);
    scanf("%i", &minuty);
    if (hodiny > 0)
    {
        sekundy = hodiny * 3600 + minuty * 60;
    }
    else if (hodiny == 0)
    {
        sekundy = minuty * 60;
    }
    printf("\nanswer:%i", sekundy);
}*/

// Napište program, který načítá roky narození pacientů.Roky budou odděleny bílým znakem.Načítání roků skončí, pokud uživatel zadá číslo 0. Program vypíše počet pacientů, kterým je podle roku narození méně než 18 let.Příklad vstupu : Zadej rok : 2001 Zadej rok : 1989 Zadej rok : 2018 Zadej rok : 0
#include <stdio.h>
int main()
{
    int year, number_of_adults = 0;

    for (int i;; i++)
    {
        printf("Enter year: ");
        scanf("%i", &year);
        if (year == 0)
        {
            break;
        }
        else if (2023 - year < 18)
        {
            number_of_adults += 1;
        }
    }
    printf("Pocet mladistvych: %i", number_of_adults);
}