#include<bits/stdc++.h>
using namespace std;

    int romanToInt(string s) {
        unordered_map<int,int> um;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'I'  && s[i+1] != 'V'  && s[i+1] != 'X'){
                um[1]++;
            }
            else if(s[i] == 'V'  && s[i-1] != 'I'){
                um[5]++;
            }
            else if(s[i] == 'X'  && s[i-1] != 'I' && s[i+1] != 'C' && s[i+1] != 'L'){
                um[10]++;
            }
            else if(s[i] == 'L' && s[i-1] != 'X'){
                um[50]++;
            }
            else if(s[i] == 'C' && s[i-1] != 'X' && s[i+1] != 'D' && s[i+1] != 'M'){
                um[100]++;
            }
            else if(s[i] == 'D' && s[i-1] != 'C'){
                um[500]++;
            }
            else if(s[i] == 'M' && s[i-1] != 'C'){
                um[1000]++;
            }
            else if(s[i] == 'I' && s[i+1] == 'V'){
                um[4]++;
            }
            else if(s[i] == 'I' && s[i+1] == 'X'){
                um[9]++;
            }
            else if(s[i] == 'X' && s[i+1] == 'L'){
                um[40]++;
            }
            else if(s[i] == 'X' && s[i+1] == 'C'){
                um[90]++;
            }
            else if(s[i] == 'C' && s[i+1] == 'D'){
                um[400]++;
            }
            else if(s[i] == 'C' && s[i+1] == 'M'){
                um[900]++;
            }
        }
        int total =0;
        for(auto it:um){
            total+=(it.second * it.first);
        }
        return total;
    }


int main(){
    string str;
    cin>>str;
    
    cout<<romanToInt(str);
    
    return 0;
}

