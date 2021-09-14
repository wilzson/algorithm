#include <cstdio>
using namespace std;

long f(long n);

int main()
{
    long n;
    scanf("%ld",&n);
    printf("%ld",f(n)%10007);
    return 0;
}

long f(long n)
{
    if(n==1 || n==2)
        return 1;
    else
        return f(n-1)+f(n-2);
}
