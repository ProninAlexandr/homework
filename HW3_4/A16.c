/*
В порядке возрастания
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

Input format
Три целых числа
Output format
Одно слово YES или NO
*/
#include <stdio.h>
int main (void)
{
    int a,b,c = 0;
    scanf("%d%d%d",&a,&b,&c);
    (a >= b) ? printf("NO"): (b >= c) ? printf("NO"): printf("YES");
    return 0;
}