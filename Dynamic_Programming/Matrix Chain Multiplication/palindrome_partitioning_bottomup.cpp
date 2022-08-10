#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isPalindrome(string str, int i, int j){
    while (i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int i, int j){
    int ans = INT_MAX, left = INT_MAX, right = INT_MAX;
    int k;
    if(i >= j){
        return 0;
    }
    if(isPalindrome(str, i, j) == true){
        return 0;
    }
    
    for(k=i; k<=j-1; k++){
        if(t[i][k] != -1){
            left = t[i][k];
        }
        else{
            left = solve(str, i ,k);
        }
        
        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }
        else{
            right = solve(str, k+1, j);
        }

        int temp = 1+left+right;
        mn = min(mn, temp);
    }
    return t[i][j] = mn;
}

int main(){
    string str;
    cin>>str;
    memset(t, -1, sizeof(t));

    cout<<solve(str, 0, str.length()-1);
    return 0;
}