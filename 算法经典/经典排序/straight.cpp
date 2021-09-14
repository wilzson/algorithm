#include<bits/stdc++.h>
using namespace std;
void StraightSort(int arr[], int len)
{
	int i,j,temp;
	for (i = 1; i < len; i++)
	{
		//数组往右逐个获取数据作为待插入到有序数组的值
		temp = arr[i];   
		
		//比较待插入值和有序数组的值，找到插入数值在有序数组中的位置
		for (j=i-1; 0 <=j && temp < arr[j]; j--) 
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
}
int main(){
    cout<<"please enter:"<<endl;
    int n,i=0;
    int result[100];
    while(cin>>n){
        if(cin.get()=='\n'){
            break;
        }
        result[i++]=n;
    }
    for(int x:result){
        cout<<x<<" ";
    }
    cout<<endl;
    StraightSort(result,i);
    for(int x:result){
        cout<<x<<" ";
    }
}