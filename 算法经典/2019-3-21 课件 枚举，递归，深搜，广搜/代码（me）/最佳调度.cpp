#include<iostream>
#include<algorithm>
using namespace std;
int n,k;//��n������k������
int time[20];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>time[i];//�������i�����ʱ��
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
