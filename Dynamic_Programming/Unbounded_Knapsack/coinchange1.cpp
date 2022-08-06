//maximum no. of ways
#include<bits/stdc++.h>
using namespace std;

int coinChangeI(int coin[], int n, int sum){
    int t[n+1][sum+1];
    t[0][0]=1;

    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(i==0){
                t[0][j]=0;
            }
            if(j==0){
                t[i][0]=1;
            }
        }
    }

   for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i][j-coin[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
   }

   return t[n][sum];
}

int main(){
    int n,sum;
    cin>>n;
    int coin[n];
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    cin>>sum;

    cout<<coinChangeI(coin, n, sum);
    return 0;
}