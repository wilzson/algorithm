#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int> > nums;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    nums.push_back(num);
    int n=nums.size();
    int m=nums[0].size();
    cout<<n<<" "<<m;
    return 0;
}