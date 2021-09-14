#include<iostream>
#include<algorithm>
using namespace std;
int n,k;//有n个任务，k个机器
int time[20];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>time[i];//完成任务i所需的时间
    }
    sort(time,time+n,greater<int>());
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans=max(ans,time[i]);
    // }
    // cout<<ans;
    return 0;
}
