#include<bits/stdc++.h>
using namespace std;

int maxAreaRectangle(int arr[][], int n, int m){
    vector<int> v;
    for(int j=0; j<m; j++){
        v.push_back(arr[0][j]);
    }
    int mx = MaxAreaHistogram(v);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                v[j] = 0;
            }
            else{
                v[j] = v[j] + arr[i][j];
            }
        }
        mx = max(mx, MaxAreaHistogram(v));
    }
    return mx;
}

int main(){
    int N,M;
    cin>>N>>M;
    int b[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>b[i][j];
        }
    }
    maxAreaRectangle(b, N, M);
    return 0;
}