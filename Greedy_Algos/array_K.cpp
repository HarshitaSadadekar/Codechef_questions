//C++ program to maximize array sum after k operations. We just have to replace the minimum element arr[i] in array by -arr[i] for current operation. One interesting case is, once the minimum element becomes 0, we don’t need to make any more changes.
#include<bits/stdc++.h>
using namespace std;

int maximumSum(int arr[], int n, int k){
    for(int i=1;i<k;i++){
        int min= INT_MAX;
        int index=-1;

        for(int j=0;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }

        if(min==0){
            break;
        }
        arr[index]=-arr[index];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int N,K; cin>>N>>K;
    int a[N],i;
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<maximumSum(a,N,K);
    return 0;
}

