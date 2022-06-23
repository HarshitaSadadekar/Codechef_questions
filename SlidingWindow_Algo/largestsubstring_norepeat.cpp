#include<bits/stdc++.h>
using namespace std;

int largestSubstringNoRepeat(string s){
    unordered_map<char,int> um;
    int i=0,j=0,max_len=0;

    while(j < s.length()){
        um[s[j]]++;
        if(um.size() > j-i+1){
            j++;
        }
        else if(um.size() == j-i+1){
            max_len = max(max_len, j-i+1);
            j++;
        }
        else if(um.size() < j-i+1){
            while(um.size() < j-i+1){
                um[s[i]]--;
                if(um[s[i]] == 0){
                    um.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return max_len;
}

int main(){
    string str;
    cin>>str;
    cout<<largestSubstringNoRepeat(str);
    return 0;
}