#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int ele, int start, int end){
    
    while(start <= end){
        int mid = start + (end-start)/2;

        // If the element is present at one of the middle 3 positions
        if(ele == arr[mid]){
            return mid;
        }
        if(mid-1 >= start && arr[mid-1]==ele){
            return mid-1;
        }
        if(mid+1 <= end && arr[mid+1]==ele){
            return mid+1;
        }
        // If element is smaller than mid, then it can only be present in left subarray
        if(ele<arr[mid]){
            return solve(n,arr,ele,start,mid-2);
        }
        // Else the element can only be present in right subarray
        if(ele>arr[mid]){
            return solve(n,arr,ele,mid+2,end);
        }
    }
    return -1;
}

int main(){
    int n,ele;
    cin>>n>>ele;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int start=0,end=n-1;
    cout<<solve(n,arr,ele,start,end);
    return 0;
}