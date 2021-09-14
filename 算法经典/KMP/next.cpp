#include<bits/stdc++.h>
/**
 * KMP�㷨���ַ���ƥ��ģ������Ӵ��������ϵ�����ĸ�±�
 * ��Ҫ��˼�������next���飬��Ŀǰ���������Ӵ���ƥ���ʱ���Ӵ���Ҫ���ݶ��ٳ���
 * next���鴢����ǵ�ǰ�Ӵ���ǰ���Ӵ�������ǰ��׺�ĳ��ȡ�
 * */
/**
 * ������Ϊ�����ں������ݣ����൱���������ʣ��ں����ڲ��ı�Ҳ�ᵼ�����鷢���ı�
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
    nextval[0]=-1;//KMP�㷨���Ż�
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
        if(j==-1||str[i]==s[j]){//�Ƚ��������Ӵ�
            ++i,++j;
        }else{
            j=nextval[j];//ģʽ�������ƶ�
        }
    }
    if(j>=s.length()){
        return i-s.length();
    }else{
        return -1;
    }
}
int main(){
    string str="aaab";//����
    string s="ab";//�Ӵ�
    int next[s.length()]={0};
    get_next(s,next);
    cout<<Index_KMP(str,s,next);
    return 0;
}