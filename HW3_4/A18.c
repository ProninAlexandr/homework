/*
Above, less, equal
Ввести два числа. Если первое число больше второго, то программа печатает слово Above. Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.

Input format
Два целых числа
Output format
Одно единственное слово: Above, Less, Equal
*/
#include <stdio.h>
int main (void)
{
    int a,b = 0;
    scanf("%d %d",&a,&b);
    (a > b) ? printf("Above"): (a < b) ? printf("Less"): (a = b) ? printf("Equal"):printf("Equal");
    return 0;
}