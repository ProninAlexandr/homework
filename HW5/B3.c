#include <stdio.h>

int main (void) {
    int a,b,c=0,i;
    scanf ("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        c+=i*i;
        }
        printf ("%d ", c);
return 0;
}