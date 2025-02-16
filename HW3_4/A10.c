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
    int a,b,c,d,e,z =0;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    z=a>b?b:a;
    z=z>c?c:z;
    z=z>d?d:z;
    z=z>e?e:z;
    printf("%d\n",z);
    return 0;

}