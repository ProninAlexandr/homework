#include <stdio.h>

int main (void) {
    int a,b, i;
    scanf ("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        printf ("%d %d", i, i*i);
        }
return 0;
}
#include <stdio.h>

int main (void) {
    int a,b,c,i=0;
    scanf ("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        c+=i*i;
        }
        printf ("%d ", c);
return 0;
}