#include<bits/stdc++.h>
using namespace std;

void countSort(int a[], int N){
    int i;
    int max= *max_element(a,a+N);
    int c[max+1];
    for(i=0;i<max+1;i++){
        c[i]=0;
    }
    for(i=0;i<N;i++){
        c[a[i]]++;
    }
    for(i=0;i<max+1;i++){
        cout<<c[i]<<" ";
    }
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    countSort(arr,n);
    
    return 0;
}