#include<bits/stdc++.h>
using namespace std;

void swap(int *c, int *b){
    int t=*c;
    *c=*b;
    *b=t;
}

int Partition(int a[], int l, int N){
    int Pivot=a[l];
    int i=l,j=N;
    do{
        do{i++;} while(a[i]<=Pivot);
        do{j--;} while (a[j]>Pivot);
        if(i<j){
            swap(a[i],a[j]);
        }        
    }
    while(i<j);
    swap(a[l],a[j]);
    return j;
}

void quickSort(int a[], int l, int N){
    if(l>=N){
        return;
    }
    int p=Partition(a,l,N);
    quickSort(a,l,p-1);
    quickSort(a,p+1,N);
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}