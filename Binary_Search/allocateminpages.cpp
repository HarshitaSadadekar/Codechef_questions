//we need to distribute such that each child has atleast one book and we need to allott in continous manner
#include<bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int k, int mx){
    int stud=1,sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>mx){
            stud++;
            sum=arr[i];
        }
        if(stud>k){
            return false;
        }
    }
    return true;
}

int solve(int n, int k, int arr[]){
    int start = *max_element(arr, arr+n);
    int end=0;
    for(int i=0; i<n; i++){
        end+=arr[i];
    }
    int res=-1, mx=INT_MIN;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(isValid(arr,n,k,mx)==true){
            res=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(n,k,arr);
    return 0;
}