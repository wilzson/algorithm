#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
// �ݹ�ⷨ��
// x1,x2,x3...xn������xiȡ0��1����ʾ��i����Ʒȡ���߲�ȡ)
// vi�����i����Ʒ�ļ�ֵ��wi�����i����Ʒ������������Ʒ��Ϊn����������Ϊc��
// ���⣺�������ֵ��max(x1v1 + x2v2 + x3v3 + ... + xnvn)
// ���ƣ�x1w1 + x2w2 + x3w3 + ... + xnwn < c
// ���庯��KS(i,j)������ǰ����ʣ������Ϊjʱ��ǰi����Ʒ����������Ӧ�ļ�ֵ��

// value��������ͷ�ļ�ֵ��volume��������ͷ�����
int value[1004]={0},volume[1004]={0};
int bp[1004][1004]={0};
int main()
{
    int n,v,t;//��ͷ�������ͱ�������������tӦ���Ǵ���
    cin>>t;
    // t��������������
    for(int z=0;z< t;z++)
    {
        cin>>n>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>value[i];//ÿ����ͷ�ļ�ֵ
        }
        for(int j=1;j<=n;j++)
        {
            cin>>volume[j];//ÿ����ͷ�����
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
//��̬�滮
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
        // ����ý���Ѿ������㣬��ôֱ�ӷ���
        if (results[i][c] != null) return results[i][c];
        if (i == 0 || c == 0){
            // ��ʼ����
            result = 0;
        } else if(ws[i] > c){
            // װ���¸��鱦
            result = ks(i-1, c);
        } else {
            // ����װ��
            int tmp1 = ks(i-1, c);
            int tmp2 = ks(i-1, c-ws[i]) + vs[i];
            result = Math.max(tmp1, tmp2);
            results[i][c] = result;
        }
        return result;
    }
}*/