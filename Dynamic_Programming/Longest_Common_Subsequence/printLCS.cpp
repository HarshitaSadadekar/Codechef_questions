//print the longest common subsequence
#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string X, string Y, int m, int n){
    int t[m+1][n+1];
    t[0][0]=0;

    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(X[i-1] == Y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    string s="";
    while(m>0 && n>0){
        if(t[m-1] == t[n-1]){
            s.push_back(X[m-1]);
            m--;
            n--;
        }
        else{
            if(t[m][n-1] > t[m-1][n]){
                n--;
            }
            else{
                m--;
            }
        }
    }

    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string X,Y;
    cin>>X;
    cin>>Y;
    cout<<longestCommonSubsequence(X, Y, X.length(), Y.length());
    return 0;
}