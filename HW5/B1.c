#include <stdio.h>

int main (void) {
    int a, i;
    scanf ("%d", &a);
    for (i =1; i <= a; i++) {
        printf ("%d %d %d\n", i, i*i, i*i*i);
        }
return 0;
}