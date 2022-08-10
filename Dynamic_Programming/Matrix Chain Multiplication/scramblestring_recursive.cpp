//Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
//USING BINARY TREES
#include<bits/stdc++.h>
using namespace std;

bool solve(string s, string t){
    if(s.compare(t) == 0){
        return true;
    }
    if(s.length() <= 1){
        return false;
    }
    int n = s.length();
    bool flag = false;

    for(int i=1; i<= n-1; i++){
        if((solve(s.substr(0,i), t.substr(n-i, i)) && solve(s.substr(i, n-i), t.substr(0, n-i))) || (solve(s.substr(0,i), t.substr(0, i)) && solve(s.substr(i, n-i), t.substr(i, n-i)))){
            flag=true;
            break;
        }
    }

    return flag;
}

int main(){
    string s,t;
    cin>>s;
    cin>>t;

    if(s.length() != t.length()){
        return false;
    }
    if(s == "" && t == ""){
        return true;
    }

    cout<<solve(s,t);
    return 0;
}