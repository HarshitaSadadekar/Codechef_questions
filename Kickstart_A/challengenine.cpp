#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    int ans=t;
    while(t--){
    string s; cin>>s;
    int sum=0,i;
    for(i=0;i<s.size();i++){
        sum+=s[i]-'0';
    }
    int insert=0;
    if(sum%9==0){
        cout<<"Case #"<<ans-t<<":"<<" "<<s[0]<<insert<<s.substr(1)<<endl;
    }
    else{
        insert=9-sum%9;
        int pos=-1;
        string out="";
        for(i=0;i<s.size();i++){
            if(s[i]-'0'>insert){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            out+=s;
            out+=to_string(insert);
        }
        else{
            out+=s.substr(0,pos);
            out+=to_string(insert);
            out+=s.substr(pos);
        }
        cout<<"Case #"<<ans-t<<":"<<" "<<out<<endl;
    }
}
    return 0;
}