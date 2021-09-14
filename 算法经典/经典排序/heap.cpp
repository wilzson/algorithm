#include<bits/stdc++.h>
using namespace std;
//堆排序，本题是根据大根堆来进行排序
//该函数是构建大根堆
void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void maxdownheap(int array[],int i,int heapsize){
    int largest=i;//假设根节点为较大值
    int left=2*i+1,right=2*i+2;//left为左节点、right为右节点
    if(left<heapsize&&array[left]>array[largest]){
        largest=left;
    }
    if(right<heapsize&&array[right]>array[largest]){
        largest=right;
    }
    if(largest!=i){//子节点大于根节点
        swap(array[largest],array[i]);//交换
        maxdownheap(array,largest,heapsize);//继续对子节点进行调节
    }
}
void buildheap(int array[],int heapsize){
    for(int i=heapsize/2-1;i>=0;i--){//从最后一个非叶子节点开始进行构建堆
        maxdownheap(array,i,heapsize);
    }
}
int main(){
    int array[]={49, 38, 65, 97, 76, 13, 27, 49, 10};
    int size = sizeof(array) / sizeof(int);
    cout<<"before"<<endl;
    print(array,size);
    buildheap(array,size);
    for(int i=size-1;i>=0;i--){//从最后一个节点开始
        swap(array[0],array[i]);
        --size;
        maxdownheap(array,0,size);
    }
    size=sizeof(array) / sizeof(int);
    cout<<"after"<<endl;
    print(array,size);
    return 0;
}