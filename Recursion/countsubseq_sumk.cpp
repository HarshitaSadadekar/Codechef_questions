#include<bits/stdc++.h>
using namespace std;

bool func(int ind, int sum, int k, int arr[], int n){
    if(ind == n){
        if(sum==k){
            return 1;
        }
        else {
            return 0;
        }
    }

    //Take or pick the particular index into the subsequence
    sum+=arr[ind];
    int l = func(ind+1, sum, k, arr, n);

    sum-=arr[ind];

    //Not take or not pick condition, this element is not added to subsequence
    int r = func(ind+1, sum, k, arr, n);

    return l+r;
}

int main(){
    int n,k; 
    cin>>n;
    cin>>k;
    int arr[n],i;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<func(0, 0, k, arr, n);
    return 0;
}