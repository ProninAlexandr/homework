#include <stdio.h>

int main (void) 
{
    int a, b=0, i=0;
    scanf ("%d", &a);
    b = a%10;
    while (a > 0)
    {
        if (b == (a%10)) i++;
        b = a%10;
        a = a/10;
    }
    (i > 1) ? printf ("YES"):printf ("NO");
return 0;
}