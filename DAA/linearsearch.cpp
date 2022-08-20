#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ele;
    cin>>n>>ele;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        if(arr[i] == ele){
            cout<<true;
        }
        else{
            cout<<false;
        }
    }
    return 0;
}