/*
Наибольшее из пяти чисел
Ввести пять чисел и найти наибольшее из них.

Input format
Пять целых чисел разделенных пробелом

Output format
Одно целое число
*/
#include <stdio.h>
int main (void)
{
    int a,b,c,d,e,z =0;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    z=a>b?a:b;
    z=z>c?z:c;
    z=z>d?z:d;
    z=z>e?z:e;
    printf("%d\n",z);
    return 0;

}