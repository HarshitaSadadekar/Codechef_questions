#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    bool t[n+1][sum+1];
    t[0][0] = true;
    int i,j;
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(i==0){
                t[0][j] = false;
            }
            if(j==0){
                t[i][0] = true;
            }
        }
    }

    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    if(sum%2 != 0){
        cout<<"false";
    }
    else if(sum%2 == 0){
        cout<<subsetSum(arr, sum/2, n);
    }
    return 0;
}