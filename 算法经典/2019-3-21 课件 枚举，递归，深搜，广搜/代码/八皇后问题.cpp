#include<iostream>
using namespace std;

int a[10]={0},b[10]={0},c[20]={0},d[20]={0},sum;
//  a���ڼ�¼�����������b��c��d���ڱ��  ���鿪��һ���ֹ���
int search(int m);
void output();

int main()
{
    search(1);
    cout<<sum<<endl;
}

int search(int i)
{
    if(i>8)
    {
        output();
        sum++;
        return 1;
    }
    for(int j=1;j<=8;j++)
    {
        //�в����жϣ�ÿһ�ж�����һ���ʺ�
        if(b[j]==0&&c[i+j]==0&&d[i-j+7]==0)//��ʾͬһ�С�����б�ߡ���б��i+j����б��i-j+7
        {
            a[i]=j;
            b[j]=1;         // ��j���ѱ�ռ��
            c[i+j]=1;       // ��б��
            d[i-j+7]=1;     //��б��
            search(i+1);    //�����ڶ����ʺ�
            b[j]=0;
            c[i+j]=0;
            d[i-j+7]=0;
        }
    }
}

void output()
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
            if(a[i]==j)
                cout<<"Q";
            else
                cout<<"#";
        cout<<endl;
    }
    cout<<endl;
}
