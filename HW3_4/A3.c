//Ввести три числа, найти их сумму.
//Output format
//Строка вида %d+%d+%d=%d
#include <stdio.h>
int main (void)
{
    int a,b,c,d = 0; //переменные
    scanf("%d %d %d", &a, &b, &c); //~Ожидает ввода знаений переменных от пользователя
    d = a + b + c;
    printf("%d+%d+%d=%d \n",a , b, c, d); //~Вывод на печать
    return 0;
}