#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    freopen("test2.in","w",stdout);
    srand((int)time(0));

    int n=1000000;
    int s=15;
    cout<<n<<" "<<s<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%20000000<<" ";
    }


    return 0;
}
