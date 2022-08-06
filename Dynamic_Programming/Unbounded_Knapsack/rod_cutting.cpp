#include<bits/stdc++.h>
using namespace std;

int rodCut(int length[], int price[], int n, int rod){
    int t[n+1][rod+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<rod+1; j++){
            if(i == 0){
                t[0][j] = 0;
            }
            if(j == 0){
                t[i][0] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<rod+1; j++){
            if(length[i-1] <= j){
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][rod];
}

int main(){
    int n;
    cin>>n;
    int length[n],price[n];
    for(int i=0; i<n; i++){
        cin>>length[i];
    }
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    int rod;
    cin>>rod;

    cout<<rodCut(length, price, n, rod);
    return 0;
}