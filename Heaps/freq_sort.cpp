#include<bits/stdc++.h>
using namespace std;

void freqSort(int size, int arr[]){
    unordered_map<int,int> um;
    priority_queue<pair<int,int>> maxh;
    vector<int> ans;
    
    for(int i=0; i<size; i++){
        um[arr[i]]++;
    }
    for(auto it=um.begin(); it!=um.end(); it++){
        maxh.push({it->second, it->first});
    }
    while(maxh.size() > 0){
        int freq = maxh.top().first;
        int elem = maxh.top().second;
        for(int i=1; i<=freq; i++){
            ans.push_back(elem);
        }
        maxh.pop();
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }       
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    freqSort(n,a);
    return 0;
}