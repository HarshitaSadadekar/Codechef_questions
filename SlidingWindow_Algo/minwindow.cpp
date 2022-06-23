#include<bits/stdc++.h>
using namespace std;

string minWindowSubString(string s,  string t){
    unordered_map<char,int> um;
    int i=0,j=0,ans=0,start=0,len=INT_MAX;

    for(i=0; i<t.length(); i++){
        um[t[i]]++;
    }
    int count= um.size();

    while(j < s.length()){
        if(um.find(s[j]) != um.end()){
            um[s[j]]--;
            if(um[s[j]]==0){
                count--;
            }
            j++;
        }
        if(count > 0){
            j++;
        }
        if(count == 0){
            while(count == 0){
                if(len > j-i+1){
                    len = min(len,j-i+1);
                    start=i;
                    ans= s.substr(start,len);
                }
                um[s[i]]++;
                if(um[s[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        }
    }
    if(len == INT_MAX){
        return "";
    }
    return s.substr(start,len);
}


int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    cout<<minWindowSubString(str1, str2);
    return 0;
}