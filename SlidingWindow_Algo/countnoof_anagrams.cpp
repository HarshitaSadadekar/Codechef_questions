#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string s1, string s2){
    unordered_map<char,int> um;
    int i=0,j=0,count,ans=0;
    int k=s2.length();

    for(i=0; i<k; i++){
        um[s2[i]]++;
    }
    count=um.size();

    while(j<s1.length()){
        if(um.find(s1[j]) != um.end()){
            um[s1[j]]--;
            if(um[s1[j]] == 0){
            count--;
        }
        }
        
        
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(count == 0){
                ans++;
            }
            if(um.find(s1[i]) != um.end()){
                um[s1[i]]++;
                if(um[s1[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;

    cout<<countAnagrams(str1,str2);
    return 0;
}