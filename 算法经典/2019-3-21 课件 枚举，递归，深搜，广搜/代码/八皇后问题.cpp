#include<iostream>
using namespace std;

int a[10]={0},b[10]={0},c[20]={0},d[20]={0},sum;
//  a用于记录，方便输出，b、c、d用于标记  数组开大一点防止溢出
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
        //行不用判断，每一行都会有一个皇后
        if(b[j]==0&&c[i+j]==0&&d[i-j+7]==0)//表示同一列、左右斜线、右斜线i+j、左斜线i-j+7
        {
            a[i]=j;
            b[j]=1;         // 第j列已被占领
            c[i+j]=1;       // 左斜线
            d[i-j+7]=1;     //右斜线
            search(i+1);    //搜索第二个皇后
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
