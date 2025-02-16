/*
Существует ли треугольник
Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

Input format
Три целых числа. Стороны треугольника a, b, c.
Output format
YES или NO
c*c=a*a+b*b
*/
#include <stdio.h>
int main (void)
{
    int a,b,c = 0;
    scanf("%d %d %d",&a,&b,&c);
    if (a > 0 && b > 0 && c > 0) 
    {
        if ((a + b) > c && (b + c) > a && (a + c) > b) 
        {
            printf("YES");
        } 
        else 
        {
            printf("NO");
        }
    }
    else printf("NO");
    return 0;
}