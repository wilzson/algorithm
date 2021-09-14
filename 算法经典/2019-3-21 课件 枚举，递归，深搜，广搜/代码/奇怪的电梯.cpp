
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int n,a,b,ans=0;
int k[210]={0},tl[2000][2]={0};

bool d[210]={0};

int head=0,tail=1;

void bfs()
{
    int now;
    do
    {
        head++;
        now=tl[head][0];
        if(now+k[now]<=n)
        {
            tail++;
            if(!d[now+k[now]])
                tl[tail][0]=now+k[now],
                tl[tail][1]=tl[head][1]+1,
                d[now+k[now]]=1;
            else tail--;
        }
        if(now-k[now]>0)
        {
            tail++;
            if(!d[now-k[now]])
                tl[tail][0]=now-k[now],
                tl[tail][1]=tl[head][1]+1,
                d[now-k[now]]=1;
            else tail--;
        }
    }while(now!=b&&head<tail);
    ans=tl[head][1];
    if(head==tail&&tl[head][0]!=b) ans=-1;
}


int main()
{
    cin>>n>>a>>b;
    if(a==b)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&k[i]);
    tl[1][0]=a;
    bfs();
    cout<<ans;
    return 0;
}
