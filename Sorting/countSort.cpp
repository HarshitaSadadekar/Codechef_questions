#include<bits/stdc++.h>
using namespace std;

void countSort(int a[], int N){
    int i;
    int max_elem= *max_element(a,a+N);
    int c[max_elem+1];
    for(i=0;i<max_elem+1;i++){
        c[i]=0;
    }
    for(i=0;i<N;i++){
        c[a[i]]++;
    }
    int j=0,k=0;
    while (k<max_elem+1){
        if(c[k]>0){
            a[j++]=k;
            c[k]--;
        }
        else{
            k++;
        }
    }
    int m_elem=0,sum=0;
    for(j=0;j<N;j=j+2){
        m_elem=max(a[j],a[j+1]);
        sum+=m_elem;
    }
    cout<<sum;
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