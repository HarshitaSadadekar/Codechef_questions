#include<bits/stdc++.h>
using namespace std;

int maxSumSubArray(int a[], int N, int K){
    int i=0,j=0,sum=0,max_sum=INT_MIN;
    while(j<N){
        sum+=a[j];
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            max_sum=max(max_sum,sum);
            sum-=a[i];
            i++;
            j++;
        }
    }
    return max_sum;
}

int main(){
    int n,i,k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSumSubArray(arr, n, k);
    return 0;
}