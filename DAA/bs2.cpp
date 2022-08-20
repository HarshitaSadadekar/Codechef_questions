#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int ele, int start, int end){

    while(start <= end){
        int mid = start + (end-start)/2;
        if(ele == arr[mid]){
            return mid;
        }
        else if(ele<arr[mid]){
            return solve(n, arr, ele, start, mid-1);
        }
        else{
            return solve(n,arr,ele,mid+1,end);
        }
    }
}

int main(){
    int n,ele;
    cin>>n>>ele;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<solve(n,arr,ele, 0, n-1);
    return 0;
}
