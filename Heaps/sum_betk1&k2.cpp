#include<bits/stdc++.h>
using namespace std;

int sumBetween(int n, int k1, int k2, int arr[]){
    
}

int main(){
    int N,K1,K2;
    cin>>N;
    cin>>K1>>K2;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    cout<<sumBetween(N,K1,K2,a);
    return 0;
}