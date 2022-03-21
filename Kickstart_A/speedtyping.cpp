#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ans=t;
    while(t--){
        string i,p;
        cin>>i;
        cin>>p;
        int cnt=0,cutoff=0;
        bool sol=false;
        for(int x=0;x<p.size();x++){
            if(p.at(x)==i.at(cnt)){
                cnt++;
                cutoff++;
            }
            if(cutoff==i.size()){
                sol=true;
                break;
            }
        }
        if(sol){
            cout<<"Case #"<<ans-t<<":"<<" "<<p.size()-i.size()<<endl;
        }
        else{
           cout<<"Case #"<<ans-t<<":"<<" "<<"IMPOSSIBLE"<<endl; 
        }
    }
    return 0;
}