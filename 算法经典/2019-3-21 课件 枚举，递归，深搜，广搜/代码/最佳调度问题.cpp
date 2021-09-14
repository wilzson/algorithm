#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#define maxint 10000000
using namespace std;

int a[105],b[105];
int i,m,n,p,k;

int zx(int *x){
    int j,t,s;
    int as;
    s=maxint;
    for(int j=1;j<=k;j++){
        if(x[j]<s){
            s=x[j];
            as=j;
        }
    }
    return as;
}

void print(int t){
    int j,s;
    s=-maxint;
    for(int j=1;j<=k;j++)
        if (b[j]>s)  s=b[j];
    printf("%d",s);
}

void search(int t){
    if (t>n) {print(t-1); return;}
    b[zx(b)]=b[zx(b)]+a[t];
    search(t+1);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>() );

    for(int i=1;i<=k;i++) b[i]=a[i];
    search(k+1);
    return 0;
}
