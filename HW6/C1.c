#include <stdio.h>

int modul (int x) 
{
    x = (x > 0)? x : (-1*x);
    return x;
}

int main (void) 
{
    int a;
    scanf ("%d", &a);
    printf ("%d", modul (a));
    return 0;
}