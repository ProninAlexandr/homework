#include "stdio.h"
int middle(int a)
{
    int i =0, s=0;
    for (i=1; i<=a;i++)
        s+=i;
        return s;

}
int main (void)
{
    int N=0;
    scanf("%d", &N);
    printf ("%d", middle (N));
    return 0;
}
