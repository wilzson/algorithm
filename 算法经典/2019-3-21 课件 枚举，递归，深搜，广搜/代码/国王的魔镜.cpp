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

int mirror(string s)                                //使用这个函数判断字符串是否是镜像的（是否是回文的）
{
    if(s.length() % 2 != 0)    return s.length();   //若字符串s是奇数位的 ，那么此时的字符串长度就是最短长度。
    string s1(s,0,s.length() / 2);
    string s2(s,s.length() / 2,s.length() / 2);     //将原字符串s从中间分成两半。一半是s1，另一半是s2;
    reverse(s2.begin(),s2.end());                   //倒置函数，相当于把字符串s2颠倒。 属于algorithm库。
    if(s1 == s2)                                    //判断字符串s是否是镜像的。
        return mirror(s1);                          //如果字符串是镜像的，再 mirror(s1) 判断 s1 是否是镜像的。
    else return s.length();                         //如果字符串并不是镜像的，那么此时的字符串长度就是最短长度。
}
