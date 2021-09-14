#include<cstdio>
#include<cstring>
using namespace std;

struct Monotone_queue
{
    static const int maxn=1000005;
    int n,k,a[maxn];
    int q[maxn],head,tail,p[maxn];//ͬ��Ŀ����һ����q�ǵ������У�p�Ƕ�Ӧ��š�

    void read()
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
    }//���벻��˵��

    void monotone_max()//�������ֵ
    {
        head=1;
        tail=0;
        for(int i=1;i<=n;++i)
        {
            while(head<=tail&&q[tail]<=a[i])
                tail--;
            q[++tail]=a[i];
            p[tail]=i;
            while(p[head]<=i-k)
                head++;
            if(i>=k)printf("%d ",q[head]);
        }
        printf("\n");
    }

    void monotone_min()
    {
        head=1;
        tail=0;
        //ΪɶҪ������?��ΪheadҪ�ϸ��Ӧ��Ԫ�أ�tailҪ�ϸ��ӦβԪ�أ����Ե�tail>=headʱ��˵����Ԫ�ء���һ��ʼ����Ϊ�գ�˵һҪ������ֵ����ʵ�����ͨ����һ����
        for(int i=1;i<=n;++i)
        {//a[i]��ʾ��ǰҪ�����ֵ
            while(head<=tail&&q[tail]>=a[i])
                tail--;
                //ֻҪ��������Ԫ�أ�����βԪ�رȴ�����ֵ�󣬼���ʾβԪ���Ѿ������ܳ��������Գ��ӡ�ֱ��βԪ��С�ڴ�����ֵ������"����"��
            q[++tail]=a[i];//������ֵ��ӡ�
            p[tail]=i;//ͬʱ��������
            while(p[head]<=i-k)
                head++;//�������Ԫ���Ѿ�"��ʱ"�����ӡ�
            if(i>=k)printf("%d ",q[head]);//�����ֵ��������Ԫ�ء�i>=k��ʾ�����������why���Լ�����Ŀ��
        }
        printf("\n");

    }
}worker;

int main()
{
    freopen("test2.in","r",stdin);
    freopen("test2.out","w",stdout);
    worker.read();
    worker.monotone_min();
    worker.monotone_max();
    return 0;
}
