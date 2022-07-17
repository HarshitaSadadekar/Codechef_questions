//Given an array print sums of all subsets in it in increasing order
#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &arr, int n, vector<int> &sumSubset){
    if(ind==n){
        sumSubset.push_back(arr[ind]);
        return;
    }
    //pick the element
    func(ind+1, sum+arr[ind], arr, n, sumSubset);

    //DO NOT pick the element
    func(ind+1, sum, arr, n, sumSubset);
}

vector<int> subsetSums(vector<int> arr, int N){
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}