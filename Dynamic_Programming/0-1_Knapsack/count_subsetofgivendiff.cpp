#include<bits/stdc++.h>
using namespace std;

int countSubsets(int arr[], int s1, int n){
    int t[n+1][s1+1];
    t[0][0] = 1;
    int i,j;
    for(i=0; i<n+1; i++){
        for(j=0; j<s1+1; j++){
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
        for(j=1; j<s1+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][s1];
}

int main(){
    int n,diff;
    cin>>n;
    cin>>diff;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    int s1 = (diff + sum)/2;

    cout<<countSubsets(arr, s1, n);
    return 0;
}