#include<bits/stdc++.h>
using namespace std;
/*
�㷨������
������������S��U
SΪ��������·���Ķ��㼯�ϣ���ʼ����ֻ��v0,ÿ���һ�����·���ͽ���Ӧ�Ķ�����뵽���ϣ�
ֱ�����ж�����뵽S�У��㷨����
UΪ��δȷ�����·���Ķ��㼯�ϣ�������̵�·�����Ȱ�����뵽S�У�ÿ����һ�����㵽S�У���Ҫ��U��
���ݽ��е�����
*/
//n���ܵĽ����,v�ǳ������,dist����̾���,preǰһ�����,matrix�ǽ����Ȩֵ
void Dijkstra(int n,int v,vector<int> &dist,vector<int> &pre,vector<vector<int> >&matrix){
    /*��һ�������������ж϶����Ƿ��Ѿ�����*/
    vector<bool> s(n+1);//�ж϶����Ƿ��Ѵ���
    for(int i=1;i<=n;i++){//�Ƚ�vֱ�������ĵ����������޸�pre�����ֵΪv
        dist[i]=matrix[v][i];
        if(dist[i]<INT_MAX) 
            pre[i]=v;
        else
            pre[i]=0;
    }
    dist[v]=0;//���㵽����ľ���Ϊ0
    s[v]=1;//����v0�Ѿ�������
    for(int i=2;i<=n;i++){//�ܵĵ�������
        int best=v;//ÿ�ε������������ݵ������ڵ㣻
        int temp=INT_MAX;
        for(int j=1;j<=n;j++){//�ҵ���̾���
            if(!s[j]&&dist[j]<temp){//����ö�����δ�������붥��vi֮���б�
                temp=dist[j];
                best=j;//�ҵ�vi����һ�ڵ����Сֵ
            }
        }
        s[best]=1;//����Ӧ���·���Ķ����Ϊ�ѷ���
        for(int j=1;j<=n;j++){//����dist��pre
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
    while(temp!=init){//��temp���������ʱ���൱����ǰ����
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
    cout<<"�����붥�����ͱ���:"<<endl;
    cin>>n>>l;
    vector<vector<int> >matrix(n+1,vector<int>(n+1,INT_MAX));//�ڽӾ�������ʾͼ
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         matrix[i][j]=INT_MAX;//��ʼ���Ƚ��ڽӾ��������������ʾ
    //     }
    // }
    int p,q,len;//������Ӧ�Ķ���ͱߵ�Ȩֵ
    /*��ֵ�ڽӾ���С��int_max��Ϊ��Ӧ��Ȩֵ*/
    for(int i=1;i<=l;i++){
        cin>>p>>q>>len;
        if(len<matrix[p][q]){//������ڱߣ��򽫶�Ӧ�ıߵ�Ȩֵ��Ϊ��Ӧ��ֵ
            matrix[p][q]=len;
            matrix[q][p]=len;//����ͼ�Ļ���Ҫ���к��ж�Ҫ�����޸�
        }
    }
    //����������dist��Ӧ��ǰ���·����preΪ��ǰ�ڵ��ǰһ�����ʵ�pre[]
    vector<int> dist(n+1,INT_MAX),pre(n+1);
    //dist�ĳ�̬Ϊ��v0��vi�л�����dist[i]ΪȨֵ��������Ϊ����
    /*�ȳ�ʼ��dist���飬ȫ����ΪINT_MAX*/
    Dijkstra(n,1,dist,pre,matrix);
    // cout<<"��1����n�����·�����ȣ�"<<endl;
    // dist�����Ѿ��洢�˳�����v0�����ԵĶ�������·��
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    cout<<"��1����n��·����"<<endl;
    printpath(pre,1,4);
    return 0;

}