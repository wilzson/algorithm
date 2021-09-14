#include<iostream>
#include<algorithm>//算法模板头文件
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int sum,num,N,j;
    int a,b,c,d,e;
    int f,g,h,l,m;
    int x[10],ok = 0;
    while(~scanf("%d",&N) && N)//while (~scanf("%d",&n)&&n)等效于 while (scanf("%d",&n)!=EOF&&n不为0)
    {
        if(ok == 0)
            ok = 1;
        else
            printf("\n");
        sum = 0;
        for(int i = 1234; i <= 98765; i++)
        {
            memset(x,0,sizeof(x));//作用是将某一块内存中的内容全部设置为指定的值
            a = i%10,b = i/10%10,c = i/100%10,d = i/1000%10,e = i/10000%10;
            num = i*N;
            if(num>98765)
                break;
            f = num%10,g = num/10%10,h = num/100%10,l = num/1000%10,m = num/10000%10;
            x[a]++,x[b]++,x[c]++,x[d]++,x[e]++;
            x[f]++,x[g]++,x[h]++,x[l]++,x[m]++;
            for(j = 0; j <= 9; j++)
                if(x[j]>1)  break;
            if(j==10)
            {
                printf("%d%d%d%d%d / %d%d%d%d%d = %d\n",m,l,h,g,f,e,d,c,b,a,N);
                sum++;
            }
            else
                continue;
        }
        if(sum==0)
            printf("There are no solutions for %d.\n",N);
    }

    return 0;
}
