/*
Наибольшее из трех чисел
Ввести три числа и найти наибольшее из них

Input format
Три целых числа через пробел

Output format
Одно наибольшее целое число
*/
#include <stdio.h>
int main (void)
{
    int a,b,c,z =0;
    scanf("%d %d %d", &a,&b,&c);
    z=a>b?a:b; //присвоение z наибольшего числа из а или б
    z=z>c?z:c; //присвоение z наибольшего числа из z или с
    printf("%d\n",z);
    return 0;
}