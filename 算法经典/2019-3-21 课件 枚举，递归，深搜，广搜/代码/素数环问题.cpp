/*
��Ŀ������
	����������N��������1~N���һ������
    ʹ��������������֮�;�Ϊ������
    ���ʱ��1��ʼ��ʱ�����У�
    ͬһ����ǡ�����һ�Ρ�N<=16
�������룺
6
���������
1 4 3 2 5 6
1 6 5 2 3 4
*/
#include<iostream>
using namespace std;

int a[25],b[25],total;
int n;

int search(int t);//����
bool pd(int x,int y);//�ж��Ƿ�Ϊ����
void print();

int main()
{
    for(int i=1;i<=20;i++) b[i]=1;
    cin>>n;
    a[1]=b[1]=1;
    search(2);
}
//�������m���ܱ�2������m֮����һ���������������Ϊ����
bool pd(int x,int y)
{
    int i,j;
    i=x+y;
    for(j=2;j*j<=i;j++)
        if(i%j==0) return 0;
    return 1;
}
//����һ���жϵķ���
// bool pd(int x,int y)//�ж������ĺ���
// {
//     int k=2,i=x+y;
//     while (k<=sqrt(i)&&i%k!=0) k++;
//     if (k>sqrt(i)) return 1;
//        else return 0;
// }


int search(int t)
{
    int i;
    if(t>n)//���t>n�����жϻ�β�ͻ�ͷ���Ƿ�Ϊ����
    {
        if ( pd(a[n],a[1]) ) print();//���pd����ֵ��1�������
        return 0;
    }
    for(i=2;i<=n;i++)
        if(pd(a[t-1],i)&& b[i]==1)
            {
                a[t]=i;
                b[i]=0;
                search(t+1);
                b[i]=1;
            }
}

void print()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
