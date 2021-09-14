#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20010;
struct node
{
    int a,b,c;
}map[100010];

int f[N*2];

bool cmp(node x,node y){return x.c>y.c;}

//查找:查找结点所在集合的根结点,
//结点 x 的根结点必然也是其父亲结点的根结点。
int find(int x)
{
    if(f[x]==x) return x;//x节点就是根节点
     return f[x]=find(f[x]);
     //返回父节点的根节点，
     //并令当前节点父节点改为直接为根节点
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);//每行输入武将的数量、武将的关系
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&map[i].a,&map[i].b,&map[i].c);
    /*初始化:初始的时候每个结点各自为一个集合,
    father[i]表示结点 i 的父亲结点,
    如果 father[i]=i,
    我们认为这个结点是当前集合根结点。*/
    for(int i=1;i<=n*2;i++)
        f[i]=i;

    //按不满意度由大到小排序
    sort(map+1,map+1+m,cmp);

    //合并
    for(int i=1;i<=m;i++)
    {
        int x=find(map[i].a);
        int y=find(map[i].b);
        if(x==y)
        {
            printf("%d\n",map[i].c);
            return 0;
        }
        f[x]=find(map[i].b+n);
        f[y]=find(map[i].a+n);
    }
    printf("0\n");
    return 0;
}
