/*
Разность двух чисел
Ввести два числа и найти их разность.

Input format
Два целых числа

Output format
Ответ - одно целое число
*/
#include <stdio.h>
int main (void)
{
    int a,b,c=0;
    scanf("%d %d", &a, &b);
    c=a-b;
    printf("%d\n",c);
    return 0;
}