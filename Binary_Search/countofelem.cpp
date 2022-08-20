//count of an element in a sorted array
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int ele){
    int start=0,end=n-1;
    int first=-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(ele == arr[mid]){
            first=mid;
            end=mid-1;
        }
        else if(ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    start=0,end=n-1;
    int last=-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(ele == arr[mid]){
            last=mid;
            start=mid+1;
        }
        else if(ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return last-first+1;
}

int main(){
    int n,ele;
    cin>>n>>ele;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<solve(n,arr,ele);
    return 0;
}