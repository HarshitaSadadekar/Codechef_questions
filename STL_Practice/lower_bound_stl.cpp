#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0) ;
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);        
    }
    int q;
    cin>>q;
    while(q--)
    {
        int y;
        cin>>y;
        int s=0;
        int e=n-1;
        int i=-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(a[m]==y)
            {
                e=m-1;
                i=m;
            }
            else if(a[m]<y) s=m+1;
            else e=m-1;
        }
        if(i!=-1)
        cout<<"Yes "<<i+1<<'\n';
        else 
        {
           vector<int>::iterator low;
           low= lower_bound(a.begin(),a.end(),y);
           cout<<"No "<<(low-a.begin())+1<<'\n';
        }
    }
    return 0;
}