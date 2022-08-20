#include<bits/stdc++.h>
using namespace std;

int getMaxPrimeFactor(int n) {
   int i, max = -1;
   while(n % 2 == 0) {
      max = 2;
      n = n/2; 
   }
   for(i = 3; i <= sqrt(n); i=i+2){ 
      while(n % i == 0) {
         max = i;
         n = n/i;
      }
   }
   if(n > 2) {
      max = n;
   }
   return max;
}

int main(){
    int n;
    cin>>n;
    int cnt=0;

    while(n>0){
        if(getMaxPrimeFactor(n) != -1 && getMaxPrimeFactor(n) != n && getMaxPrimeFactor(n) != 1){
            n = getMaxPrimeFactor(n);
            cnt++;
        }
        else{
            n = n-1;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}