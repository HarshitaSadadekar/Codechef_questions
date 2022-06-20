#include<bits/stdc++.h>
using namespace std;

int longestSubarray(int a[], int n, int k){
    int sum=0,maxsize=0,i=0,j=0;

    while(j < n){
        sum+= a[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxsize = max(maxsize, j-i+1);
            j++;
        }
        else if(sum > k){
            while(sum > k){
                sum-=a[i];
                i++;
            }
        }
    }
    return maxsize;
}

int main(){
    int N,i,K;
    cin>>N;
    cin>>K;
    int arr[N];
    for(i=0; i<N; i++){
        cin>>arr[i];
    }
    cout<<longestSubarray(arr,N,K);
    return 0;
}