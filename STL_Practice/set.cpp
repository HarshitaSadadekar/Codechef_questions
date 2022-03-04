#include<bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    set<int> s;
    while(q--){
        int y,x; cin>>y>>x;

        if(y==1){
            s.insert(x); 
        }
        else if(y==2){
            s.erase(x);
        }
        else if(y==3){
            if(s.find(x)!=s.end()){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}