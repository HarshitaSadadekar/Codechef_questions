#include<bits/stdc++.h>
using namespace std;

void func(int ind, vector<int> &v, int arr[], int n){
    //Base condition
    if(ind == n){
        for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //Take or pick the particular index into the subsequence
    v.push_back(arr[ind]);
    func(ind+1, v, arr, n);
    v.pop_back();

    //Not take or not pick condition, this element is not added to subsequence
    func(ind+1, v, arr, n);
}

int main(){
    int n; cin>>n;
    int arr[n],i;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> v;
    func(0, v, arr, n);
    return 0;
}