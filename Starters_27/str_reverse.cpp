#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s; cin>>s;
        string r=s;
        reverse(r.begin(),r.end());
        long long i=0,j=0,ans=0;
        while(i<s.length()){
            if(s[i]==r[j]){
                j++;
            } else{
                ans++;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}