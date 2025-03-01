#include <stdio.h>

int main (void) {
    int a, i=0;
    scanf ("%d", &a);
    while (a) {
        a=a/10;
        i++;
        }
    (i == 3) ? printf ("YES"): printf ("NO");
    
return 0;
}