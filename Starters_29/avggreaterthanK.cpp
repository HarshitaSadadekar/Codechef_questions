#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k; cin>>k;
    
    double ans = 0;
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += a[i];
    }
        ans = (double)sum / k;
        for(int i = 1; i < n-k+1; i++){
            sum += a[i+k-1];
            sum -= a[i-1];
            ans = max(ans, (double)sum/k);
        }
        return ans;
    }
}