/*

#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{

    int a = 2;
    int b = 5;
    swap(&a, &b);
    printf("\n%i", a);
    printf("\n%i", b);
    // int *p; //указатель на интеджер
    //   p=&i;// в p вложим ходноту i;
    // printf("%i\n", i);
    // printf("%i\n", *p);
    // * přistup do paměti , & přistup do hodnoty
    // указатели нужны, чтобы менять значения переменных в функции
}

#include <stdio.h>
void div(double *a, double *b)
{
    double temp_a = *a;
    double temp_b = *b;
    double res = temp_a / temp_b;
    return res;
}
int main(void)
{

    int a = 8;
    int b = 2;

    // swap(&a, &b);
    printf("\n%i", div(&a, &b));
    // printf("\n%i", b);
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
    double res;
    div(&a, &b, &res);
    printf("\n%.3f", res);
}

#include <stdio.h>


     struct Point {
        double a;
        double b;
    };
void reverse(struct Point *point  ){
    double temp=point->b;
    point->b=point->a;
    point->a=temp;
}
int main(void){

     struct Point p ={.a=-3.2, .b=1.3};
 reverse (&p);
 printf("%.3f %.3f", p.a, p.b);
*/

/*
    int *p[3];
    int a=2;
    int b=3;
    int c =4;
    p[0]=&a;
    p[1] = &b;
    p[2] = &c;
    printf("\n%d", *p[1]);
*/
#include <stdio.h>
int main()
{
    int i = 1;
    int *ptr = &i;
    printf("%i", ptr);
}
