#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string X, string Y, int m, int n){
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
    int i=m,j=n;
    while(i>0 && j>0){
        if(t[i-1] == t[j-1]){
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(Y[j-1]);
                j--;
            }
            else{
                s.push_back(X[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(X[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(Y[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string X,Y;
    cin>>X;
    cin>>Y;
    cout<<shortestCommonSupersequence(X, Y, X.length(), Y.length());
    return 0;
}