// Given an array a, we have to find the minimum product possible with the subset of elements present in the array. The minimum product can be a single element also.

#include<bits/stdc++.h>
using namespace std;

int minProductSubset(int arr[], int N){
    int max_neg=0,min_pos=0,count_neg=0,count_zero=0,prod=1;
    for(int i=0;i<N;i++){
        if(arr[i]==0){
            count_zero++;
            continue;
        }
        else if(arr[i]<0){
            count_neg++;
            max_neg=max(max_neg,arr[i]);
        }
        else if(arr[i]>0){
            min_pos= min(min_pos,arr[i]);
        }

        prod=prod*arr[i];
    }

    if(count_zero>0 && count_neg==0){
        return 0;
    }
    else if((count_neg|1 >count_neg) && (count_zero==0)){
        return prod/max_neg;
    }
    else if((count_neg|1 <count_neg) && (count_zero==0)){
        return prod;
    }
    else if(count_zero==0 && count_neg==0){
        return min_pos;
    }
}

int main(){
    int n; cin>>n;
    int a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<minProductSubset(a,n);
    return 0;
}