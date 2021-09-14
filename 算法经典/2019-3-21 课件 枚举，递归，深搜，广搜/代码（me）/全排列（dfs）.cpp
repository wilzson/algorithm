#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void dfs(int step);
int n;
int book[10]={0};
int a[10]={0};
int main()
{
    cin>>n;//有多少张扑克
    dfs(1);
    return 0;
}
void dfs(int step)//step表示当前要处理的盒子 
{
    if(step>n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    for(int i = 1; i <= n; i++)
    {
        if(book[i] == 0)
        {
            a[step] = i; //将i号扑克牌放入第step个盒子中 
            book[i] = 1; // 置1表示第i号扑克牌不在手中
            dfs(step+1);//递归调用
            book[i]=0;// 非常重要，收回该盒子中的扑克牌才能进行下一次尝试。
        }
    }
}
