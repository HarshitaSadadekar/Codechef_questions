#include<bits/stdc++.h>
using namespace std;

void insertionSort1(int a[], int N){
    int i,j,x;
    for(i=1;i<N;i++){
        j=i-1;
        x=a[i];
        while(j>-1 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort1(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}