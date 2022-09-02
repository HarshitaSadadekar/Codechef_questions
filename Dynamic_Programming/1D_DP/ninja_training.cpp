//Ninja is planning this N days-long training schedule. Each day, he can perform any 1 one these 3 activities. (Running, Fighting practice or Learning new moves). Each activity has some merit points on each day. As ninja has to improve all his skills, he cant do the same activity in two consecutive days. Can you help ninja find out the maximum merit points ninja can earn?

//2-D array of size N*3 POINTS with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that ninja can earn

//MEMORIZATION
#include<bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int task=0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }
    int maxi=0;
    for(int task=0; task<3; task++){
         if(task != last){
            int point = points[day][task] + solve(day-1, task, points, dp);
            maxi = max(maxi, point);
        }   
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n,  vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return solve(n-1, 3, points, dp);
}

//TABULATION
int ninjaTraining(int n,  vector<vector<int>> &points){
    vector<int> prev(4,0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][1], points[0][1], points[0][2]);

    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int last=0; last<4; last++){
            temp[last]=0;

            for(int task=0; task<3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev=temp;
    }

    
    return prev[3];
}