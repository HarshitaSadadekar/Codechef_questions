#include<bits/stdc++.h>
using namespace std;

int sumBetween(int n, int k1, int k2, int arr[]){
    priority_queue<int> maxh1;
    priority_queue<int> maxh2;
    
    for(int i=0; i<n; i++){
        maxh1.push(arr[i]);
        if(maxh1.size()>k1){
            maxh1.pop();
        }
    }
    int bottom=maxh1.top();

    for(int i=0; i<n; i++){
        maxh2.push(arr[i]);
        if(maxh2.size()>k2){
            maxh2.pop();
        }
    }
    int top=maxh2.top();

    int sum=0;
    for(int i=0; i<n; i++){
        if(arr[i]>bottom && arr[i]<top){
            sum+=arr[i];
        }
    }

    return sum;
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