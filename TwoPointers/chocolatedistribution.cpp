#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int a[], int n, int m){
    //if no.of students or the chocolates is 0 
    if(m == 0 || n== 0){
        return 0;
    }
    sort(a, a+n);
    //no.of students cannot be more than the no. of chocolates
    if(m > n){
        return -1;
    }

    int min_diff = INT_MAX;
    int diff;
    
    for(int i=0; i+m-1 < n; i++){
        diff = a[i+m-1] - a[i];
        if(diff < min_diff){
            min_diff =diff;
        }
    }
    return min_diff;
}

int main(){
    int i,N,M;
    cin>>N>>M;
    int arr[N];
    for(i=0; i<N; i++){
        cin>>arr[i];
    }
    findMinDiff(arr,N,M);
    return 0;
}