#include<bits/stdc++.h>
using namespace std;

long solve(int ind, int buy, long *values, int n){
    if(ind == n) return 0;

    long profit=0;
    if(buy){
        profit = max(-values[ind] + solve(ind+1, 0, values, n), 0 + solve(ind+1, 1, values, n));
    }
    else{
        profit = max(values[ind] + solve(ind+1, 1, values, n), 0 + solve(ind+1, 0, values, n));
    }

    return profit;
}

long getMaximumProfit(long *values, int n){
    vector<vector<long>> dp(n+1, vector<long>(2,0));
    dp[n][0] = dp[n][1] = 0;

    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else{
                profit = max(values[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}