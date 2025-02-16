/*
Наибольшее из двух чисел
Ввести два числа и вывести их в порядке возрастания.

Input format
Два целых числа

Output format
Два целых числа
*/
#include <stdio.h>
int main (void)
{
    int a,b=0;
    scanf("%d %d", &a, &b);
    if (a<b) printf("%d %d", a,b);
    else printf("%d %d", b,a);
    return 0;
}