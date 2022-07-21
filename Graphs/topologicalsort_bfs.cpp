//Kahn's Algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> topoSort(int N, vector<int> adj[]){
        queue<int> q;
        vector<int> indegree(N,0);
        for(int i=0; i<N; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<N; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        //int count=0; 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            //count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        // if(count==N){
        //     return false;
        // }
        return topo;
    }
}