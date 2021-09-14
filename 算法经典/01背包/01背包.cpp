#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
// 递归解法：
// x1,x2,x3...xn，其中xi取0或1，表示第i个物品取或者不取)
// vi代表第i个物品的价值，wi代表第i个物品的重量，总物品数为n，背包容量为c。
// 问题：求出最大价值：max(x1v1 + x2v2 + x3v3 + ... + xnvn)
// 限制：x1w1 + x2w2 + x3w3 + ... + xnwn < c
// 定义函数KS(i,j)：代表当前背包剩余容量为j时，前i个物品最佳组合所对应的价值；

// value数组代表骨头的价值，volume数组代表骨头的体积
int value[1004]={0},volume[1004]={0};
int bp[1004][1004]={0};
int main()
{
    int n,v,t;//骨头的数量和背包的最大体积，t应该是次数
    cin>>t;
    // t代表背包的最大体积
    for(int z=0;z< t;z++)
    {
        cin>>n>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>value[i];//每个骨头的价值
        }
        for(int j=1;j<=n;j++)
        {
            cin>>volume[j];//每个骨头的体积
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=v;j++)
            {
                if(j<volume[i])
                    bp[i][j]=bp[i-1][j];
                else
                    bp[i][j]=max(bp[i-1][j],bp[i-1][j-volume[i]]+value[i]);
            }
        }
        cout<<bp[n][v]<<endl;
    }
    return 0;
}
//动态规划
/*public class Solution{
    int[] vs = {0,2,4,3,7};
    int[] ws = {0,2,3,5,5};
    Integer[][] results = new Integer[5][11];

    @Test
    public void testKnapsack2() {
        int result = ks2(4,10);
        System.out.println(result);
    }

    private int ks2(int i, int c){
        int result = 0;
        // 如果该结果已经被计算，那么直接返回
        if (results[i][c] != null) return results[i][c];
        if (i == 0 || c == 0){
            // 初始条件
            result = 0;
        } else if(ws[i] > c){
            // 装不下该珠宝
            result = ks(i-1, c);
        } else {
            // 可以装下
            int tmp1 = ks(i-1, c);
            int tmp2 = ks(i-1, c-ws[i]) + vs[i];
            result = Math.max(tmp1, tmp2);
            results[i][c] = result;
        }
        return result;
    }
}*/