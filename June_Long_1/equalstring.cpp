#include<bits/stdc++.h>
using namespace std;

void solution(){
    vector<int> M(26,0);
    int N;
    string A,B;
    cin>>N;
    cin>>A;
    cin>>B;

    for(int i=0;i<N;i++){
        if(B[i] != A[i]){
            M[B[i]-'a']=1;
        }
    }
    int min_op= accumulate(M.begin(), M.end(), 0);
    cout<<min_op<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solution();
    }
    return 0;
}