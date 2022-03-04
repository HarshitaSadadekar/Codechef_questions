#include<bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    map<string, int> m;
    string key;
    for(int i=0,value;i<q;i++){
        int y;
        cin>>y>>key;

        if(y==1){
            cin>>value;
           m[key]+=value;
        }
        else if(y==2){
          m.erase(key);  
        }
        else if(y==3){
            cout<<m[key]<<endl;
        }
    }
    return 0;
}