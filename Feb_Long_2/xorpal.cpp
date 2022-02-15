#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt0=0;
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        cnt0++; //counting the number of 0's in the string
        else
        cnt1++; //counting the number of 1's in the string
    }
    if(cnt0%2==0 && cnt1%2==0) //if number of 1's and 0's is even => Xor palindrome
    return "yes";
    else if(cnt0==cnt1) //if number of 1's and 0's is equal => Xor palindrome
    return "yes";
    else if((cnt0%2==0 && cnt1%2!=0) || (cnt0%2!=0 && cnt1%2==0)) //if either of them is odd => Xor palindrome
    return "yes";
    else
    return "no";
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