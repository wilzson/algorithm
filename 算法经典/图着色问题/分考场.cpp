/**
 * n个人参加某项特殊考试。
　　为了公平，要求任何两个认识的人不能分在同一个考场。
　　求是少需要分几个考场才能满足条件。
输入格式
　　第一行，一个整数n(1<n<100)，表示参加考试的人数。
　　第二行，一个整数m，表示接下来有m行数据
　　以下m行每行的格式为：两个整数a，b，用空格分开 (1<=a,b<=n) 表示第a个人与第b个人认识。
输出格式
　　一行一个整数，表示最少分几个考场。
 * */
#include<bits/stdc++.h>
using namespace std;
int n,m;//n代表参加考试的人数，m行数据
int grah[100][100]={0};//定义一个邻接矩阵，存储点之间的关系
int exam[100][100]={0};//用一个二维数组来代表第i个考场中的第j个学生是谁
//如count[1][1]=1，count[1][2]=0,第1个考场的第一个学生是1，第二个学生等于0表示没有，则这时cnt[1]=1;
int cnt[100]={0};//表示第i个考场的学生数量
int result=0x3f3f3f3f;//考场的数量

void solve(int id,int num)//id为第i个学生，num表示为当前的考场数量
{
    if(num>=result){              //当现在安排的数量已经大于了最小的教室数量的话，返回
        return;
    }
    if(id>n)//表示学生数量已经超过n的最大数量，表示所有学生已经分配完
    {
        result=min(result,num);
        return;
    }
    for(int i=1;i<=num;i++)//先判断能不能安排进之前的考场
    {
        int sz=cnt[i];//先获取当前考场的学生数量
        int unfriends=0;//与之前的学生不认识的个数
        for(int j=1;j<=sz;j++)
        {
            if(grah[id][exam[i][j]]==0)
            {
                unfriends+=1;
            }
        }
        if(unfriends==sz)//表示该考生与之前的学生都不认识
        {
            exam[i][++cnt[i]]=id;
            solve(id+1,num);
            cnt[i]--;
        }

    }
    // 与前面的考生都认识，只能重新开一间考场
    exam[num+1][++cnt[num+1]]=id;
    solve(id+1,num+1);
    --cnt[num+1];
}

int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        grah[a][b]=grah[b][a]=1;
    }
    solve(1,0);
    cout<<result;
    return 0;
}