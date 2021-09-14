#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf=INT_MAX/2;
        // 建立一个邻接矩阵来表示图
        vector<vector<int>> matrix(n,vector<int>(n,inf));
        // 有向图只需要源节点到目标节点的单条线，如果是无向图的话，matrix[y][x]=t[2]
        for(auto &t:times){//初始化
            int x=t[0]-1;
            int y=t[1]-1;
            matrix[x][y]=t[2];
        }
        vector<int> dist(n,inf);//当前最短距离
        // 将k节点也就是源节点放进队列中，dist[k-1]=0
        dist[k-1]=0;
        // 标记数组元素是否被使用
        vector<bool> used(n);
        // 总的迭代次数
        for(int i=0;i<n;i++){
            // 每次迭代都将起点回溯，寻找下一个最短路径
            int x=-1;
            for(int y=0;y<n;y++){
                // 如果该节点还未被访问且与顶点vi之间有边，找到最短路径的节点
                if(!used[y]&&(x == -1 || dist[y] < dist[x])){
                    x=y;
                }
            }
            used[x]=true;
            // 将x设为已访问，并更新最短距离
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + matrix[x][y]);
            }
        }
        // 找到距离最远的点
        int ans = *max_element(dist.begin(), dist.end());
        return (ans == inf) ? -1 : ans;
    }