//Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true
//The input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}
#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

int solve(string s, int i, int j, bool isTrue){
    int ans=0;

    if(i > j){
        return false;
    }
    if(i == j){
        if(isTrue == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }

    for(int k=i+1; k<=j-1; k=k+2){
        int lt = solve(s,i,k-1,true);
        int lf = solve(s,i,k-1,false);
        int rt = solve(s,k+1,j,true);
        int rf = solve(s,k+1,j,false);

        if(s[k] == '&'){
            if(isTrue == true){
                ans+= lt*rt;
            }
            else{
                ans+= lf*rt + rf*lf + lt*rf;
            }
        }
        else if(s[k] == '|'){
            if(isTrue == true){
                ans+= lt*rt + lf*rt + lt*rf;
            }
            else{
                ans+= rf*lf ;
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans+= lf*rt + lt*rf;
            }
            else{
                ans+= lt*rt + rf*lf ;
            }
        }
    }

    return mp[temp]=ans;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s, 0, s.length()-1, true);
    return 0;
}