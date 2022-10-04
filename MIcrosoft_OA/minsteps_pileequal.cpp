//Alexa is given n piles of equal or unequal heights. In one step, Alexa can remove any number of boxes from the pile which has the maximum height and try to make it equal to the one which is just lower than the maximum height of the stack. Determine the minimum number of steps required to make all of the piles equal in height.

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
    map<int,int> mp;
    priority_queue<int> maxh;

    for(int i=0; i<n; i++){
        if(mp.find(arr[i]) != mp.end()){
            maxh.push(arr[i]);
        }
        mp[arr[i]]++;
    }
    
    int cnt=0,steps=0;
    while(maxh.size() != 1){
        int top = maxh.top();
        maxh.pop();
        int secondTop = maxh.top();
        steps+=mp[top];
        mp[secondTop] = mp[top] + mp[secondTop];
    }

    return cnt;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);
    return 0;
}