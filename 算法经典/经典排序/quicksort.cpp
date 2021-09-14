#include<bits/stdc++.h>
using namespace std;
//思路：分治递归
// 选定一个基数x(一开始默认为数组首地址)，将数组分为前面小于x的区间和后面大于x的区间，再分别递归对
// 两个区间再进行快速排序，直到全部有序
void quickSort(int arr[],int start,int end){
    if(start<end){//递归条件
        //把数组的第一个数字作为基数
        int startnum=arr[start];
        //标记高位和低位
        int low = start;
        int high = end;
        // 循环进行排序
        while (low<high)
        {
            //高位的数如果比标准数大，则高位向左移
			while(low<high&&startnum<=arr[high]){
				high--;
			}
			//不是，则高位数与低位交换
			arr[low]=arr[high];
			//低位的数如果比标准数小，则低位右移
			while(low<high&&arr[low]<=startnum){
				low++;
			}
			//不是，则低位与高位交换
			arr[high]=arr[low];
        }
        //高低位重合，低位或者高位下标赋值，值为标准数
		arr[low]=startnum;
		//递归左半边
		quickSort(arr, start, low);
		//递归右半边
		quickSort(arr, low+1, end);
    }
}
int main(){
    int num[]={1,3,2,5,4,6,9,8,7,10,12,11,13};
    int n=sizeof(num)/sizeof(int);
    quickSort(num,0,n-1);
    for(int x:num){
        cout<<x<<" ";
    }
    cout<<endl;
}