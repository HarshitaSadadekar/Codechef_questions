#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int key, int low, int high){
    int bitonicPoint=0;;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1]>arr[mid]){
                bitonicPoint =  solve(arr, n, key, mid, high);
            }
            else{
                bitonicPoint = solve(arr, n, key, low, mid);
            }
        }
        else if(mid==0){
            if(arr[0]>arr[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(mid==n-1){
            if(arr[n-1]>arr[n-2]){
                return n-1;
            }
            else{
                return n-2;
            }
        }
    }
}

int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int low=0,high=n-1;
    cout<<solve(arr, n, key, low, high);
    return 0;
}