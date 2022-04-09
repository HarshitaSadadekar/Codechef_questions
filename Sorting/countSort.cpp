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
    int j=0,k=0;
    while (k<max+1){
        if(c[k]>0){
            a[j++]=k;
            c[k]--;
        }
        else{
            k++;
        }
    }
    for(i=0;i<N;i++){
        cout<<a[i]<<" ";
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