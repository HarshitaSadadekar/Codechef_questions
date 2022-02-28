#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int i,c;
    vector<int> vec;
    for(i=1;i<=n;i++){
        cin>>c;
        vec.push_back(c);
    }
    int q; cin>>q;
    while(q--){
        int y;
        cin>>y;
        auto loc= find(vec.begin(), vec.end(), y);
        if(loc!= vec.end()){
            cout<<"Yes"<<" "<<loc-vec.begin()+1<<endl;
        }
        else{
            for(i=1;i<=n;i++){
                if(vec[i]>y){
                    cout<<"No"<<" "<<i+1<<endl;
                    break;
                }
            }
        }
    }
}