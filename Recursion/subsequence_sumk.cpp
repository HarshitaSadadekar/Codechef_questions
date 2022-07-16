#include<bits/stdc++.h>
using namespace std;

void func(int ind, vector<int> &v, int sum, int k, int arr[], int n){
    if(ind == n){
        if(sum==k){
            for(int i=0; i<v.size(); i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //Take or pick the particular index into the subsequence
    v.push_back(arr[ind]);
    sum+=arr[ind];
    func(ind+1, v, sum, k, arr, n);
    sum-=arr[ind];
    v.pop_back();

    //Not take or not pick condition, this element is not added to subsequence
    func(ind+1, v, sum, k, arr, n);
}

int main(){
    int n,k; 
    cin>>n;
    cin>>k;
    int arr[n],i;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> v;
    func(0, v, 0, k, arr, n);
    return 0;
}