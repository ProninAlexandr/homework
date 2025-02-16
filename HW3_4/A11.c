/*
Наименьшее из пяти чисел
Ввести пять чисел и найти  наименьшее из них.

Input format
Пять целых чисел
Output format
Одно целое число
*/
#include <stdio.h>
int main (void)
{
    int a,b,c,d,e,x,y,z =0;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    z=a>b?b:a;
    z=z>c?c:z;
    z=z>d?d:z;
    z=z>e?e:z;
    y=a>b?a:b;
    y=y>c?y:c;
    y=y>d?y:d;
    y=y>e?y:e;
    x=y+z;
    printf("%d\n",x);
    return 0;

}