//Number of insertions to make a string palindrome == number of deletions to make a string palindrome
//minimum number of deletions to make a string palindrome
#include<bits/stdc++.h>
using namespace std;

int minInsertions(string X, string Y){
    int m = X.length(); 
    int n = Y.length();
    
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

    return m-t[m][n];
}

int main(){
    string a;
    cin>>a;
    string b=a;
    reverse(b.begin(), b.end());
    cout<<minInsertions(a, b);
    return 0;
}