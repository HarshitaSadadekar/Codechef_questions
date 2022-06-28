#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[], int n){
    vector<int> v;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < arr[i]){
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= arr[i]){
            while(s.size() > 0 && s.top() >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
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