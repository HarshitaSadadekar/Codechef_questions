#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i; cin>>n;
    vector<int> a;
    for(i=0;i<n;i++){
        int c; cin>>c;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
    int ans= abs(a[0]-a[1]);
    for(i=1;i<a.size();i++){
        if(abs(a[i]-a[i-1])<ans){
            ans=abs(a[i]-a[i-1]);
        }
    }
    cout<<ans;
    return 0;
}