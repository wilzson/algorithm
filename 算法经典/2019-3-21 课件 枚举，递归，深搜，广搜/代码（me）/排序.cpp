#include<iostream>
#include<algorithm>
using namespace std;
void swap(int* a)
{
    int temp;
    temp=a[0];
    a[0]=a[1];
    a[1]=temp;
}
int main()
{
    int x,y;//输入两个整数
    cin>>x>>y;
    int a[2];
    a[0]=x,a[1]=y;
    swap(a);
    cout<<a[0]<<" "<<a[1];
    return 0;
}