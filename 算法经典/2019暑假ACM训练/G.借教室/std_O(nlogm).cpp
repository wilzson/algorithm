#include<stdio.h>
#include<string.h>
#define N 1000005
int room[N],d[N],s[N],t[N],sum[N];
long long a[N];
int n,m;
void init()
{
    int i;
    scanf("%d%d",&n,&m);
    for ( i=1; i<=n; i++) scanf("%d",&room[i]);
    for ( i=1; i<=m; i++) scanf("%d%d%d",&d[i],&s[i],&t[i]);
}
int judge(int ad)
{
    memset(a,0,sizeof(a));
    int i;
    for ( i=1; i<=ad; i++)
    {
        a[s[i]]+=d[i];
        a[t[i]+1]-=d[i];
    }
    long long num = 0;
    for (i=1; i<=n; i++)
    {
        num+=a[i];
        if (num>room[i])
            return 0;
    }
    return 1;
}
void work()
{
    int l=0,r=m+1;
    while (l+1<r)
    {
        int mid=(l+r)/2;
        if (judge(mid))
            l=mid;
        else
            r=mid;
    }
    if (l==m) printf("0\n");
    else printf("-1\n%d\n",l+1);
}
int main()
{
    init();
    work();
    return 0;
}
