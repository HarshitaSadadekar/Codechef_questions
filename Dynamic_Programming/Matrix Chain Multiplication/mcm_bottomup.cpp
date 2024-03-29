#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

int solve(int arr[], int i, int j){
    int mn = INT_MAX;
    int k;
    if(i >= j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    for(k=i; k<=j-1; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] *arr[j];
        mn = min(mn, temp);
    }
    return t[i][j] = mn;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(t, -1, sizeof(t));

    cout<<solve(arr, 1, n-1);
    return 0;
}