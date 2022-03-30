#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int s; cin>>s;
        int ans=0;
        if(s>0){
            ans=-(s+1);
        }
        else if(s<0){
            ans=s-1;
        }
        else if(s==0){
            ans=-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}