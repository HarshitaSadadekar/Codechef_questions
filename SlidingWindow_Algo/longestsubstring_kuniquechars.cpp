#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s ,int k){
    unordered_map<char,int> um;
    int i=0,j=0, max_len =INT_MIN;

    while(j < s.length()){
        um[s[j]]++;
        if(um.size() < k){
        }
        else if(um.size() == k){
            max_len = max(max_len, j-i+1);
        }
        else if(um.size() > k){
            while(um.size() > k){
                um[s[i]]--;
                if(um[s[i]] == 0){
                    um.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return max_len;
}

int main(){
    string str;
    int K;
    cin>>str;
    cin>>K;
    cout<<longestSubstring(str, K);
    return 0;
}