#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

void print_permutation(int n,int *A,int cur);

int main()
{
    int n;
    scanf("%d",&n);//输入n个数
    int A[20];
    print_permutation(n,A,0);
}

void print_permutation(int n,int *A,int cur){
    if(cur==n){//当现在的值等于n值，输出
        for(int i=0;i<n;i++) printf("%d",A[i]);
        printf("\n");
    }
    else{
        for(int i=1;i<=n;i++){
            int ok=1;
            for(int j=0;j<cur;j++)
                if(A[j]==i) ok=0;
            if(ok){
                A[cur]=i;
                print_permutation(n,A,cur+1);
            }
        }
    }
}
