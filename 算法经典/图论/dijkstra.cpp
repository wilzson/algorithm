#include<bits/stdc++.h>
using namespace std;
/*
算法描述：
先设两个集合S，U
S为已求出最短路径的顶点集合，初始化是只有v0,每求出一条最短路径就将对应的顶点加入到集合，
直到所有顶点加入到S中，算法结束
U为尚未确定最短路径的顶点集合，按照最短的路径长度按序加入到S中，每加入一个顶点到S中，都要对U中
数据进行调整。
*/
//n是总的结点数,v是出发结点,dist是最短距离,pre前一个结点,matrix是结点间的权值
void Dijkstra(int n,int v,vector<int> &dist,vector<int> &pre,vector<vector<int> >&matrix){
    /*设一个布尔数组来判断顶点是否已经处理*/
    vector<bool> s(n+1);//判断顶点是否已处理
    for(int i=1;i<=n;i++){//先将v直接相连的点给提出来，修改pre数组的值为v
        dist[i]=matrix[v][i];
        if(dist[i]<INT_MAX) 
            pre[i]=v;
        else
            pre[i]=0;
    }
    dist[v]=0;//顶点到自身的距离为0
    s[v]=1;//顶点v0已经访问了
    for(int i=2;i<=n;i++){//总的迭代次数
        int best=v;//每次迭代都将起点回溯到出发节点；
        int temp=INT_MAX;
        for(int j=1;j<=n;j++){//找到最短距离
            if(!s[j]&&dist[j]<temp){//如果该顶点尚未访问且与顶点vi之间有边
                temp=dist[j];
                best=j;//找到vi到下一节点的最小值
            }
        }
        s[best]=1;//将对应最短路径的顶点改为已访问
        for(int j=1;j<=n;j++){//更新dist和pre
            if(!s[j]&&matrix[best][j]!=INT_MAX){
                int newdist=dist[best]+matrix[best][j];
                if(newdist<dist[j]){
                    dist[j]=newdist;
                    pre[j]=best;
                }

            }
        }
    }
}
void printpath(vector<int> pre,int init,int final){
    int temp=final;
    vector<int> t;
    while(temp!=init){//当temp不等于起点时，相当于往前回溯
        t.push_back(temp);
        temp=pre[final];
        final=temp;
    }
    cout<<init<<"->";
    for(int i=t.size();i>1;i--){
        cout<<t[i-1]<<"->";
    }
    cout<<t[0];
    t.clear();
}
int main(){
    int n,l;
    cout<<"请输入顶点数和边数:"<<endl;
    cin>>n>>l;
    vector<vector<int> >matrix(n+1,vector<int>(n+1,INT_MAX));//邻接矩阵来表示图
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         matrix[i][j]=INT_MAX;//初始化先将邻接矩阵都用无穷大来表示
    //     }
    // }
    int p,q,len;//两个对应的顶点和边的权值
    /*赋值邻接矩阵，小于int_max即为对应的权值*/
    for(int i=1;i<=l;i++){
        cin>>p>>q>>len;
        if(len<matrix[p][q]){//如果存在边，则将对应的边的权值改为对应的值
            matrix[p][q]=len;
            matrix[q][p]=len;//无向图的话需要将行和列都要进行修改
        }
    }
    //设两个数组dist对应当前最短路径，pre为当前节点的前一个访问点pre[]
    vector<int> dist(n+1,INT_MAX),pre(n+1);
    //dist的初态为若v0到vi有弧，则dist[i]为权值，否则置为无穷
    /*先初始化dist数组，全部设为INT_MAX*/
    Dijkstra(n,1,dist,pre,matrix);
    // cout<<"点1到点n的最短路径长度："<<endl;
    // dist数组已经存储了出发点v0到各自的顶点的最短路径
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    cout<<"点1到点n的路径："<<endl;
    printpath(pre,1,4);
    return 0;

}