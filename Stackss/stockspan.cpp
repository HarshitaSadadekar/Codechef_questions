#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[], int n){
    vector<int> v;
    stack<pair<int,int>> s; //store the element and its index

    for(int i=0; i<n; i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first > arr[i]){
            v.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for(int i=0; i<v.size(); i++){
        v[i] = i-v[i];
    }
    return v;
    
}

int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    vector<int> ans = nearestGreaterToLeft(a,N);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}