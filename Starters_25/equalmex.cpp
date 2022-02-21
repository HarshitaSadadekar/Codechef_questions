#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int> a(2*n);
        map<int,int> cnt;
        for(int i=0;i<2*n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }

        int flag=1;
        for(int i=0;i<=n;i++){
            if(!cnt[i]){
                break;
            }
            else if(cnt[i]==1)
            flag=0;
        }
    if(flag==1)
    cout<<"yes\n";
    else
    cout<<"no\n";
    }
    return 0;
}