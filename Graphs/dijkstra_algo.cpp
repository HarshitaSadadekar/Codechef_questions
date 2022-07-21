#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int>> g[n+1]; //1-indexed adjacency list for the graph

    int a,b,wt;
    for(int i=0; i<m; i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cin>>source;

    //Dijkstra's Algorithm begins from here
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
    vector<int> distTo(n+1, INT_MAX);

    distTo[source]=0;
    minh.push(make_pair(0, source));

    while(!minh.empty()){
        int dist = minh.top().first;
        int prev = minh.top().second;
        minh.pop();

        vector<pair<int,int>>::iterator it;
        for(auto it:g[prev]){
            int next = it.first;
            int nextDist = it.second;
            if(distTo[next] > dist + nextDist){
                distTo[next] = dist + nextDist;
                minh.push(make_pair(distTo[next], next));
            }
        }
    }
    cout<<"The distances from the source, "<<source<<", are : \n";
    for(int i=1; i<=n; i++){
        cout<<distTo[i]<<" ";
    }
    return 0;
}