//Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.
//min heap approach
#include<bits/stdc++.h>
using namespace std;

int solve(int *a, int *b, int n, int m, int k){
    priority_queue<int,vector<int>,greater<int>> minh;

    for(int i=0; i<n; i++){
        minh.push(a[i]);
    }
    for(int i=0; i<m; i++){
        minh.push(b[i]);
    }

    while(minh.size()>k){
        minh.pop();
    }

    return minh.top();
}

int main(){
    int arr1[5] = {2,3,6,7,9};
    int arr2[4] = {1,4,8,10};
    int k=5;

    cout<<solve(arr1, arr2, 5, 4, k-1);
    return 0;
}