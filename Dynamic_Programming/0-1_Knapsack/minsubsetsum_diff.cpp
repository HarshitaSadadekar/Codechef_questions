#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(int arr[], int n, int sum){
    int t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0){
                t[0][j]=0;
            }
            if(j==0){
                t[i][0]=1;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> v;
    for(int j=0; j<=sum/2; j++){
        if(t[n][j] == 1){
            v.push_back(j);
        }
    }
        
    int mn=INT_MAX;
    for(int i=0; i<v.size(); i++){
        mn = min(mn, sum - 2*v[i]);
    }
        
    return mn;   
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

    cout<<minSubsetSumDiff(arr, n, sum);
    return 0;
}