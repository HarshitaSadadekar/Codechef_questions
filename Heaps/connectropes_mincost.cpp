#include<bits/stdc++.h>
using namespace std;

int minCost(int n, int arr[]){
    priority_queue<int, vector<int>, greater<int>> minh;
    int cost=0;

    for(int i=0; i<n; i++){
        minh.push(arr[i]);
    }
    while(minh.size() >= 2){
        int first = minh.top();
        minh.pop();
        int second = minh.top();
        minh.pop();
        cost+= first+second;
        minh.push(first+second);
    }
    return cost;
}

int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    cout<<minCost(N,a);
    return 0;
}