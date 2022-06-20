#include<bits/stdc++.h>
using namespace std;

vector<int> maxFromSubarray(int a[], int n,int k){
    int i=0,j=0;
    list<int> l;
    vector<int> ans;

    while(j<n){
        while(l.size() > 0 && l.back() < a[j]){
            l.pop_back();
        }
        l.push_back(a[j]);

        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            ans.push_back(l.front());
            if(l.front() == a[i]){
                l.pop_front();
                i++;
                j++;
            }
        }
    }
    return ans;
}

int main(){
    int N,i,K;
    cin>>N;
    cin>>K;
    int arr[N];
    for(i=0; i<N; i++){
        cin>>arr[i];
    }
    
    return 0;
}