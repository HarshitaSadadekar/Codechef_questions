#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin>>N>>m;
    vector<pair<int,int>> adj[N];

    int a,b,wt;
    for(int i=0; i<m; i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    int parent[N];
    int key[N];
    bool mstSet[N];

    for(int i=0; i<N; i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

    key[0]=0;
    parent[0]=-1;
    minh.push({0,0});

    for(int c=0; c<N-1; c++){
        int u = minh.top().second;
        minh.pop();
        mstSet[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v] == false && weight < key[v]){
                parent[v]=u;
                minh.push({key[v], v});
                key[v]=weight;
            }
        }
    }
    for(int i=1; i<N; i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return 0;
}