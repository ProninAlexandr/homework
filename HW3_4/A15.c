/*
Уравнение прямой
Определить уравнение прямой по координатам двух точек. Уравнение вида
y=k*x+b
Input format
Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2
Output format
Два числа K,B в формате "%.2f %.2f"
*/
#include <stdio.h>
int main (void)
{
   int  y1,y2,x1,x2=0;
   float k,k1,k2,b=0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    k1=y1-y2;
    k2=x1-x2;
    k=k1/k2;
    b=y2-k*x2;
    printf("%.2f %.2f",k,b);
}