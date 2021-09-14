#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;
int n,m,x,y,index_,dfn[maxn],low[maxn],ans,a;//index_代表当前的时间戳
vector<int>G[maxn];//存边的数据结构：邻接表

struct Edge{int from,to;}edge[maxn];//答案的边，最后需要排序

bool cmp(const Edge a,const Edge b){
    if(a.from!=b.from)
        return a.from<b.from;
    return a.to<b.to;
}//答案边的比较函数

inline void add_edge(int x,int y){
    edge[ans].from=min(x,y);
    edge[ans].to=max(x,y);
    ans++;
}//在答案中加入一条边

void dfs(int cur,int fa)    //cur是当前节点，fa是他的父亲
{
    int child;
    dfn[cur]=++index_;//计算当前节点的时间戳
    low[cur]=dfn[cur];//当前可以访问到的最早时间戳肯定是自己的时间戳

    for(int i=0;i<G[cur].size();i++)//遍历cur的所有出点
    {
        child=G[cur][i];
        if(dfn[child]&&child!=fa)
            low[cur]=min(low[cur],dfn[child]);//如果访问到了不是父亲节点的节点，更新low的值

        if(!dfn[child]) //如果这个节点之前没有被访问过
        {
            dfs(child,cur);//进行一次dfs过程
            if(dfn[cur]<low[child])
                add_edge(cur,child);//如果满足条件，在答案序列中加入这条边
            low[cur]=min(low[cur],low[child]);//更新low的值
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y),
            G[x].push_back(y),G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i,i);
    //图可能不连通，初始时fa是i不会出现问题

    sort(edge,edge+ans,cmp);//将答案序列排个序

    for(int i=0;i<ans;i++)printf("%d %d\n",edge[i].from,edge[i].to);//输出

    return 0;
}
