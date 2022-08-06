#include<bits/stdc++.h>
using namespace std;

int countSubsets(int arr[], int sum, int n){
    int t[n+1][sum+1];
    t[0][0] = 1;
    int i,j;
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(i==0){
                t[0][j]=0;
            }
            else if(j==0){
                t[i][0]=1;
            }
        }
    }

    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int n, sum;
    cin>>n;
    cin>>sum;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<countSubsets(arr, sum, n);
    return 0;
}