#include "stdio.h"


uint_32t zerno (int z)
{
    int i;
    long long unsigned int calc =1;
    for (i=1;i<z;i++)
    calc*=2;
    return calc;
}
int main (void)
{
    int N;
    scanf("%d", &N);
    printf("%llu", zerno(N));
    return 0;
}