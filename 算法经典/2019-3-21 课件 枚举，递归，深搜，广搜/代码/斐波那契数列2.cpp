#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    long a=1;
    long b=1;
    long c=1;
    long d;
    long n;
    long i;

    scanf("%ld",&n);
    if (n<=3)
    {
        d=1;
    }
    for (i=4;i<=n;i++)
    {
        d=a+b+c;
        d%=10007;
        a=b;
        b=c;
        c=d;
    }
    printf("%ld\n",d);

    return 0;
}
