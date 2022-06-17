#include<bits/stdc++.h>
using namespace std;

void firstNegativeint(int a[],int n,int k){
    list<int> l;
    int i=0,j=0;
    vector<int> vec;

    while(j<n){
        if(a[j] < 0){
            l.push_back(a[j]);
        }
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(l.size() == 0){
                vec.push_back(0);
            }
            else{
                vec.push_back(l.front());
                if(a[i] == l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
    }
    for(i=0; i<vec.size(); i++){
        cout<<vec[i];
    }
}

int main(){
    int N,K,i;
    cin>>N; cin>>K;
    int arr[N];
    for(i=0; i<N; i++){
        cin>>arr[i];
    }
    firstNegativeint(arr,N,K);
    return 0;
}