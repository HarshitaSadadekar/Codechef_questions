#include<bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, int cap, vector<int> &prices, int n){
    if(ind==n || cap==0) return 0;

    if(buy==1){
        return max(-prices[ind] + solve(ind+1,0,cap,prices,n), 0 + solve(ind+1,1,cap,prices,n));
    }
    return max(prices[ind] + solve(ind+1,1,cap-1,prices,n), 0 + solve(ind+1,0,cap,prices,n));
}

int maxProfit(vector<int> &prices, int n){
    return solve(0,1,2,prices,n);
}