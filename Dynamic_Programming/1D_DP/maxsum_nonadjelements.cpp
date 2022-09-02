//You are given an array of N integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array
#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i > 1){
            take+=prev2;
        }
        int notTake = 0+prev;
        int curi = max(take, notTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}