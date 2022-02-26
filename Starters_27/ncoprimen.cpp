#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
   ll t; cin>>t;
   while(t--){
       ll n; cin>>n;
       ll a[n];
       for(int i=0;i<n;i++){
           cin>>a[i];
       }

       for(int i=0;i<n;i++){
           if(i%3==0){
               continue;
           }
           if(i%3==1){
               a[i]=a[i-1]*2;
           }
           else{
               if(i+1<n){
                   a[i]=a[i+1]*2;
               }
               else{
                   a[i]=a[i-1];
               }
           }
       }
   } 
}