/*������һ��ħ�������԰��κνӴ�����Ķ������ԭ������������ֻ�ǣ�
��Ϊ�Ǿ�������ӵ��ǲ����Ƿ��ġ�
����һ��������������AB����ʾ��
��ͬ����ĸ��ʾ��ͬ��ɫ�����顣
�����B�˽Ӵ�����Ļ���ħ���������������ΪABBA��
�������һ�˽Ӵ��Ļ��������ABBAABBA���ٶ�����ֻ��������ĳһ�˽Ӵ�ħ������
�������յ����������д�����������ûʹ��ħ��֮ǰ��������������ܵ���С����*/
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
