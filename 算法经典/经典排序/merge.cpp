#include <iostream>
using namespace std;
int a[1000], b[1000];
int k=0;
/*归并排序本质上是分治法。先通过递归不断的向下划分，
直到每个分组只有一个数，再对对应的左右分组进行合并。
合并是通过双指针，分别指向左右数组，*/
void Merge(int *a, int *b, int begin, int mid, int end) {
    int pb = 0;
    int p1 = begin, p2 = mid + 1;//双指针，分别指向左数组和右数组
    while (p1 <= mid && p2 <= end) {
        if (a[p1] <= a[p2])
            b[pb++] = a[p1++];
        else
            b[pb++] = a[p2++];
    }
    //当其中一个数组遍历完，则将另外数组的剩余元素存入到中间数组
    while (p1 <= mid)
        b[pb++] = a[p1++];
    while (p2 <= end)
        b[pb++] = a[p2++];
    //将中间数组排序过后的元素放入到原数组a中
    for (int i = 0; i < end - begin + 1; ++i) {
        a[begin + i] = b[i];
    }
}

void Merge_Sort(int *a, int *b, int begin, int end) {
    if (begin < end) {
        //取中间数，对左右数组进行划分
        int mid = begin + (end - begin) / 2;
        Merge_Sort(a, b, begin, mid);
        Merge_Sort(a, b, mid + 1, end);
        Merge(a, b, begin, mid, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cout<<"输入你要排序的数字：";
    while (cin >> n) {
        a[k++] = n;
        if (cin.get() == '\n')   //cin输入吃到了回车就不继续读入了
            break;
    }
    cout << k << "位" << endl;
    Merge_Sort(a, b, 0, k - 1);
    for (int i = 0; i < k; ++i) {
        cout << a[i]<<" ";
    }
    return 0;
}
