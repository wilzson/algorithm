#include<bits/stdc++.h>
using namespace std;
/*
�鲢����ĵ���ʵ��
*/
//��vec[begin1, ... ,end1]�� vec[end1+1, ... ,end_2]�ϲ����ŵ�temp��
void mergeTwo(vector<int> &vec, int begin1, int end1, int end2) {
    int i = begin1, j = end1+1, k = 0;
    vector<int> temp(end2 - begin1 + 1);    // ��ʱ���飬���ڴ��������������ϲ���Ľ��
    while (i <= end1 && j <= end2) {
        if (vec[i] < vec[j]) {
            temp[k++] = vec[i++];          
        }
        else {
            temp[k++] = vec[j++];          
        }
    }
    while (i <= end1) {
        temp[k++] = vec[i++];
    }
    while (j <= end2) {
        temp[k++] = vec[j++];
    }
    // �úϲ���Ľ��temp��vec[begin1,... ,end_2]���ǵ�
    for (int i = 0; i < end2-begin1+1; ++i) {
        vec[begin1 + i] = temp[i];
    }
}
void mergeSort(vector<int>& result){
    const int sz=result.size();
    for(int width=1;width<sz;width*=2){
        for(int i=0;i<sz;i+=2*width){
            mergeTwo(result,i,min( i + width - 1,sz-1), min(i + 2 * width - 1, sz - 1));
        }
    }
}
int main(){
    vector<int> result={1,4,3,2,7,6,5,9,8};
    mergeSort(result);
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}