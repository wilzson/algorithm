#include<bits/stdc++.h>
/**
 * KMP算法是字符串匹配的，返回子串在主串上的首字母下标
 * 主要的思想是求出next数组，当目前的主串与子串不匹配的时候，子串需要回溯多少长度
 * next数组储存的是当前子串的前面子串的最长相等前后缀的长度。
 * */
/**
 * 数组作为参数在函数传递，是相当于引用性质，在函数内部改变也会导致数组发生改变
 * */
using namespace std;
void get_next(string s,int nextval[]){
    // int i=0,j=-1;
    // nextval[0]=-1;
    // while(i<s.length()-1){
    //     if(j==-1||s[i]==s[j]){
    //         ++i,j++;
    //         if(s[i]!=s[j]){
    //             nextval[i]=j;
    //         }else{
    //             nextval[i]=nextval[j];
    //         }
    //     }else{
    //         j=nextval[j];
    //     }
        
    // }
    int i=0,j=-1;
    nextval[0]=-1;//KMP算法的优化
    while(i<s.length()-1){
        if(j==-1||s[i]==s[j]){
            i++,j++;
            if(s[i]!=s[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }else{
            j=nextval[j];
        }
    }

}
int Index_KMP(string str,string s,int nextval[]){
    // int i=0,j=0;
    // while(i<str.length()&&j<s.length()){
    //     if(j==-1||str[i]==s[j]){
    //         i++,j++;
    //     }else{
    //         j=nextval[j];
    //     }
    // }
    // if(j>=s.length())
    //     return i-s.length();
    // else
    //     return -1;
    int i=0,j=0;
    while(i<str.length()&&j<s.length()){
        if(j==-1||str[i]==s[j]){//比较主串和子串
            ++i,++j;
        }else{
            j=nextval[j];//模式串向右移动
        }
    }
    if(j>=s.length()){
        return i-s.length();
    }else{
        return -1;
    }
}
int main(){
    string str="aaab";//主串
    string s="ab";//子串
    int next[s.length()]={0};
    get_next(s,next);
    cout<<Index_KMP(str,s,next);
    return 0;
}