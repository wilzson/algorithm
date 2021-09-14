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

//����:���ҽ�����ڼ��ϵĸ����,
//��� x �ĸ�����ȻҲ���丸�׽��ĸ���㡣
int find(int x)
{
    if(f[x]==x) return x;//x�ڵ���Ǹ��ڵ�
     return f[x]=find(f[x]);
     //���ظ��ڵ�ĸ��ڵ㣬
     //���ǰ�ڵ㸸�ڵ��Ϊֱ��Ϊ���ڵ�
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);//ÿ�������佫���������佫�Ĺ�ϵ
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&map[i].a,&map[i].b,&map[i].c);
    /*��ʼ��:��ʼ��ʱ��ÿ��������Ϊһ������,
    father[i]��ʾ��� i �ĸ��׽��,
    ��� father[i]=i,
    ������Ϊ�������ǵ�ǰ���ϸ���㡣*/
    for(int i=1;i<=n*2;i++)
        f[i]=i;

    //����������ɴ�С����
    sort(map+1,map+1+m,cmp);

    //�ϲ�
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
