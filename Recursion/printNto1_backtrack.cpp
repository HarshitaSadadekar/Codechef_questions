#include<bits/stdc++.h>
using namespace std;

int func(int n,int i){
    if(i>n){
        return -1;
    }
    func(n,i+1);
    cout<<i<<endl;
}

int main(){
    int n; cin>>n;
    func(n,1);
    return 0;
}