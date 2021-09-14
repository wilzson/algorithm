#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;
int n,m,x,y,index_,dfn[maxn],low[maxn],ans,a;//index_����ǰ��ʱ���
vector<int>G[maxn];//��ߵ����ݽṹ���ڽӱ�

struct Edge{int from,to;}edge[maxn];//�𰸵ıߣ������Ҫ����

bool cmp(const Edge a,const Edge b){
    if(a.from!=b.from)
        return a.from<b.from;
    return a.to<b.to;
}//�𰸱ߵıȽϺ���

inline void add_edge(int x,int y){
    edge[ans].from=min(x,y);
    edge[ans].to=max(x,y);
    ans++;
}//�ڴ��м���һ����

void dfs(int cur,int fa)    //cur�ǵ�ǰ�ڵ㣬fa�����ĸ���
{
    int child;
    dfn[cur]=++index_;//���㵱ǰ�ڵ��ʱ���
    low[cur]=dfn[cur];//��ǰ���Է��ʵ�������ʱ����϶����Լ���ʱ���

    for(int i=0;i<G[cur].size();i++)//����cur�����г���
    {
        child=G[cur][i];
        if(dfn[child]&&child!=fa)
            low[cur]=min(low[cur],dfn[child]);//������ʵ��˲��Ǹ��׽ڵ�Ľڵ㣬����low��ֵ

        if(!dfn[child]) //�������ڵ�֮ǰû�б����ʹ�
        {
            dfs(child,cur);//����һ��dfs����
            if(dfn[cur]<low[child])
                add_edge(cur,child);//��������������ڴ������м���������
            low[cur]=min(low[cur],low[child]);//����low��ֵ
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
    //ͼ���ܲ���ͨ����ʼʱfa��i�����������

    sort(edge,edge+ans,cmp);//���������Ÿ���

    for(int i=0;i<ans;i++)printf("%d %d\n",edge[i].from,edge[i].to);//���

    return 0;
}
