#include "stdio.h"
int power(int n, int p)
{
    int s=1,i;
    for (i=1;i<=p;i++)
    s*=n;
    return s;
}
int main (void)
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf ("%d", power (a,b));
    return 0;
}