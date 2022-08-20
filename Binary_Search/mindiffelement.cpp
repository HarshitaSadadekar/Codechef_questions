//find minimum diff elementin a sorted array
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int key){
    int start=0,end=n-1;

    while(start<=end){
        int mid=start + (end-start)/2;

        if(arr[mid] == key){
            return 0;
        }
        else if(arr[mid] > key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    if(end>=0 && start<=n-1){
        if(abs(key-arr[start]) > abs(key-arr[end])){
            return abs(key-arr[end]);
        }
        else{
            return abs(key-arr[start]);
        }
    }
    else if(end>=0){
        return abs(key-arr[end]);
    }

    
    return abs(key-arr[start]);
}

int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<solve(n,arr,key);
    return 0;
}