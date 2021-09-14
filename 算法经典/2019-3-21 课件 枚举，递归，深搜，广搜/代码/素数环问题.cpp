/*
题目描述：
	输入正整数N，把整数1~N组成一个环，
    使得相邻两个整数之和均为素数。
    输出时从1开始逆时针排列，
    同一个环恰好输出一次。N<=16
样例输入：
6
样例输出：
1 4 3 2 5 6
1 6 5 2 3 4
*/
#include<iostream>
using namespace std;

int a[25],b[25],total;
int n;

int search(int t);//搜索
bool pd(int x,int y);//判断是否为素数
void print();

int main()
{
    for(int i=1;i<=20;i++) b[i]=1;
    cin>>n;
    a[1]=b[1]=1;
    search(2);
}
//如果整数m不能被2到根号m之间任一整数整除，则该数为素数
bool pd(int x,int y)
{
    int i,j;
    i=x+y;
    for(j=2;j*j<=i;j++)
        if(i%j==0) return 0;
    return 1;
}
//另外一种判断的方法
// bool pd(int x,int y)//判断素数的函数
// {
//     int k=2,i=x+y;
//     while (k<=sqrt(i)&&i%k!=0) k++;
//     if (k>sqrt(i)) return 1;
//        else return 0;
// }


int search(int t)
{
    int i;
    if(t>n)//如果t>n，则判断环尾和环头和是否为素数
    {
        if ( pd(a[n],a[1]) ) print();//如果pd返回值是1，则输出
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
