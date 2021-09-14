#include<bits/stdc++.h>
using namespace std;
int main(){
    string name="hello";
    cout<<typeid(1).name()<<endl;
    for(auto i:name){
        cout<<typeid(i).name();
    }
    return 0;
}