#include<iostream>
#include<cstring>
#include<algorithm>
#include<functional>

using namespace std;

int mirror(string s);

int main()
{
    string len;
    cin>>len;
    cout<<mirror(len);
}

int mirror(string s)                                //ʹ����������ж��ַ����Ƿ��Ǿ���ģ��Ƿ��ǻ��ĵģ�
{
    if(s.length() % 2 != 0)    return s.length();   //���ַ���s������λ�� ����ô��ʱ���ַ������Ⱦ�����̳��ȡ�
    string s1(s,0,s.length() / 2);
    string s2(s,s.length() / 2,s.length() / 2);     //��ԭ�ַ���s���м�ֳ����롣һ����s1����һ����s2;
    reverse(s2.begin(),s2.end());                   //���ú������൱�ڰ��ַ���s2�ߵ��� ����algorithm�⡣
    if(s1 == s2)                                    //�ж��ַ���s�Ƿ��Ǿ���ġ�
        return mirror(s1);                          //����ַ����Ǿ���ģ��� mirror(s1) �ж� s1 �Ƿ��Ǿ���ġ�
    else return s.length();                         //����ַ��������Ǿ���ģ���ô��ʱ���ַ������Ⱦ�����̳��ȡ�
}
