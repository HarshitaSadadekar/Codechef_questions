#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string p = s.substr(0,1);
    int cost=1;
    
    for(int i=1; i<s.length(); i++){
        int n = p.length();
        if(n == s.length()){
            break;
        }
        if(s.substr(i, n) == p){
            p.append(s, i, n);
        }
        else{
            p.append(s, i, 1);
            cost++;
        }
    }
    cout<<cost;
    return 0;
}