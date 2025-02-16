/*
Какое время года
Ввести номер месяца и вывести название времени года.

Input format
Целое число от 1 до 12 - номер месяца.
Output format
Время года на английском: winter, spring, summer, autumn
*/
#include <stdio.h>
int main (void)
{
    int a = 0;
    scanf("%d",&a);
    (a <= 2) ? printf("winter"): (a <= 5) ? printf("spring"): (a <= 8) ? printf("summer"): (a<= 11) ? printf("autumn"): (a<=12)?printf("winter"):printf("error");
    return 0;
}