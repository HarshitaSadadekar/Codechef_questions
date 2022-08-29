// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.)
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: 2
// Explanation:
// We need two meeting rooms
// room1: (0,30)
// room2: (5,10),(15,20)

//APPROACH
// Here we are using a priority queue so that we can keep track of the earliest ending meeting. If the start of current meeting isn't greater or equal to the end value of top element in the priority queue, we need an extra room to accommodate the meeting and hence we push the element into the priority queue. Otherwise, we pop the top element and push the current element(i.e., we re-use the room). Eventually, the size of priority queue turns out to be our answer.
#include<bits/stdc++.h>
using namespace std;

struct comp{
    bool operator()(vector<int> p1, vector<int> p2){
        return p1[1] > p2[1];
    }
};

int solve(vector<vector<int>> &v){
    int n=v.size();
    if(n==0)return 0;
    sort(v.begin(),v.end());
    priority_queue<vector<int>, vector<vector<int>>, comp> minh;
    minh.push(v[0]);

    for(int i=1; i<n; i++){
        vector<int> temp=minh.top();
        int x=temp[1];
        if(v[i][0] < x){
            minh.push(v[i]);
        }
        else{
            minh.pop();
            minh.push(v[i]);
        }
    }
    return minh.size();
}
