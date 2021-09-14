/**
 * 并查集算法主要分为查找根节点，合并节点
 * */
#include<bits/stdc++.h>
using namespace std;
int parent[500];//定义一个父节点集合
void init(int n){//初始化森林
    for(int i=1;i<=n;i++){
        parent[i]=i;//初始化，将每个点的父亲节点设为自己
    }
}
int find(int x){//查询根节点(递归方法，没有路径压缩)
    if(parent[x]==x)//找到根节点，只有根节点的父亲节点是自己
    {
        return x;
    }
    else
    {
        return find(parent[x]); 
    }
}
int find2(int x){//查询根节点(递归方法，有路径压缩，将多次递归的节点直接指向根节点)
    if(parent[x]==x){
        return x;
    }else{
        parent[x]=find2(parent[x]);
        return parent[x];
    }
}
void Union(int root1,int root2){
    int t1,t2;//设t1,t2为对应的根节点
    t1=find2(root1);
    t2=find2(root2);
    if(t1!=t2){//判断两个节点是否在同一集合中，即是否为同一祖先
        parent[t2]=t1;//靠左原则，右边集合作为左边集合的子集合
    }
    return;
}
int main(){
    int x,y;
    int sum;
    init(5);
    for(int i=1;i<=5;i++){
        cin>>x>>y;
        Union(x,y);
    }
    for(int i=1;i<=5;i++){
        if(parent[i]==i){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}