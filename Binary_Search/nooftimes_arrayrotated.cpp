//the number of a sorted array is rotated is equal to the index of the minimum element
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[]){
    int start=0, end = n-1;

    while(start <= end){
        int mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
            
        if(arr[start] < arr[end]){
            return start;
        }
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            return mid;
        }
        else if(arr[start] <= arr[mid]){
            start=mid+1;
        }
        else if(arr[end] >= arr[mid]){
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<solve(n,arr);
    return 0;
}