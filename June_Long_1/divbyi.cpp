#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int arr[n]={0};

        ll temp=n;
        for(int i=n;i>=1;i-=2){
            arr[i]=temp;
            temp--;
        }

        ll temp2=1;
        for(int i=n-1; i>0; i-=2){
            arr[i]=temp2;
            temp2++;
        }
        for(int i=1;i<n+1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}