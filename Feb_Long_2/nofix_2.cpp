#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a;
        for(int i=1;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
        }

        int inserted=0;
        for(int i=1;i<n;i++){
            if(a[i]==(i+inserted)){
                inserted++;
            }
        }
        cout<<inserted<<endl;
    }
    return 0;
}