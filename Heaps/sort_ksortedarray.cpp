#include<bits/stdc++.h>
using namespace std;

void sortKsortedArray(int size, int arr[], int k){
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> v;

    for(int i=0; i<size; i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            v.push_back(minh.top());
            minh.pop();
        }
    }
    while(minh.size()>0){
        v.push_back(minh.top());
        minh.pop();
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int n,K;
    cin>>n;
    cin>>K;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sortKsortedArray(n,a,K);
    return 0;
}