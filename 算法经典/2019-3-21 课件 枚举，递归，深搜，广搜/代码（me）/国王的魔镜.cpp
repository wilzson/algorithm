/*国王有一个魔镜，可以把任何接触镜面的东西变成原来的两倍——只是，
因为是镜子嘛，增加的那部分是反的。
比如一条项链，我们用AB来表示，
不同的字母表示不同颜色的珍珠。
如果把B端接触镜面的话，魔镜会把这条项链变为ABBA。
如果再用一端接触的话，则会变成ABBAABBA（假定国王只用项链的某一端接触魔镜）。
给定最终的项链，请编写程序输出国王没使用魔镜之前，最初的项链可能的最小长度*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int func(string s);
int main()
{
    string s1;
    cin>>s1;
    cout<<func(s1);
    return 0;
}
int func(string s)
{
    if(s.length()%2!=0)
        return s.length();
    string s1;
    int len=s.length();
    for(int i=0;i<(len+1)/2;i++)
    {
        if(s[i]!=s[len-1-i])
        {
            return len;
        }
    }
    for(int i=0;i<(s.length()+1)/2;i++)
    {
        s1[i]=s[i];
    }
    return func(s1);
}
