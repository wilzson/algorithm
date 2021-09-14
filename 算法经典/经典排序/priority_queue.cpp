#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> a;
    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    }
    return 0;
}