/*问题描述：
	在国际象棋棋盘上放八个皇后，要求她们相互之间不会攻击到对方
输出所有的解
*/
#include<iostream>
#include<cmath>
using namespace std;
void search(int cur);
int main()
{

}
void search(int cur)
{
    if(cur==n)
        tot++;
    else
        for(int i=0;i<n;i++)
        {
            int ok=1;
            c[cur]=i;
            for(int j=0;j<cur;j++)
            {
                if(c[cur]==c[j]||cur-C[cur]==j-c[j]||cur+c[cur]==j+c[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                search(cur+1);
        }
}
