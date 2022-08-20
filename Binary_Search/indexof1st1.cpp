//index of the 1st 1 in an infinite binary sorted array
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
    int start=0,end=1,mid;

    while(arr[end]==0){
        start=end;
        end=end*2;
    }

    int res = -1;
    while(start <= end){
        mid = start+(end-start)/2;
        if(1 == arr[mid] && (mid==0 || arr[mid-1]==0)){
           break;
        }
        else if(1 == arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return mid;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr, n);
    return 0;
}