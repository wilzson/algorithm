#include<cstdio>
const int M=1000005;
int n,m,i,x,cnt,a[M],b[M],l[M],r[M],d[M];

//输入加速
int read()
{
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9') x=(x<<1)+(x<<3)+ch-48,ch=getchar();
    return x;
}

int main()
{
    n=read(),m=read();
    for (i=1;i<=n;++i){
        //a[i]=(b[i]=read())-b[i-1];
        scanf("%d",&b[i]);
        a[i]=b[i]-b[i-1];
    }

    /*测试用*/
//    for(int i=1;i<=n;i++)
//        printf("%d ",a[i]);
//    printf("\n");

    for (i=1;i<=m;++i){
        //d[i]=read(),a[l[i]=read()]=a[l[i]]-d[i],a[(r[i]=read())+1]=a[r[i]+1]+d[i];
        scanf("%d%d%d",&d[i],&l[i],&r[i]);
        a[l[i]]=a[l[i]]-d[i];
        a[r[i]+1]=a[r[i]+1]+d[i];
    }


    /*测试用*/
//    for(int i=1;i<=n+1;i++)
//        printf("%d ",a[i]);
//    printf("\n");
    x=m;
    cnt=0;
    for (i=1;i<=n;++i){
        for (cnt=cnt+a[i];cnt<0;--m){//从后往前删除指令，直到没有负数为止
//            printf("i=%d cnt=%d\n",i,cnt);
            if (l[m]>i){
                a[l[m]]=a[l[m]]+d[m];
                a[r[m]+1]=a[r[m]+1]-d[m];
            }
            else
                if (r[m]>=i){
                    cnt=cnt+d[m];
                    a[r[m]+1]=a[r[m]+1]-d[m];
                }

        }

//        for(int i=1;i<=n+1;i++)
//            printf("%d ",a[i]);
//        printf("\n");
    }
//    printf("cnt= %d\n",cnt);
    if (m<x)
        printf("-1\n%d\n",m+1);
    else
        printf("0\n");
    return 0;
}
