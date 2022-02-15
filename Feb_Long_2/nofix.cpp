#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        a.push_back(c);
    }
    int ans=0; //min number of operations
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==i+1)
        {
            ans++; 
            a.insert(a.begin()+i,a.size()+1); //insert a number 1 greater than size of the vector at the i'th index
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<'\n';
    }
    return 0;
}