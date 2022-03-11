#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int ans=0,i;
        for(i=0;i<n;i++){
            if(s[i]==s[i+1]){
                ans++;
                i++;
            }
            else{
                ans=ans+1;
            }
        }  
        cout<<ans<<"\n";
    }
    return 0;
}