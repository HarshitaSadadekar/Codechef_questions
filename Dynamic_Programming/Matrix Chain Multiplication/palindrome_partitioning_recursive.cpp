//find minimum no. of partitions such that every one is a palindrome
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j){
    while (i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int i, int j){
    int ans=INT_MAX;

    if(i >= j){
        return 0;
    }
    if(isPalindrome(str, i, j) == true){
        return 0;
    }
    for(int k=i; k<=j-1; k++){
        int temp = solve(str, i, k) + solve(str, k+1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<solve(str, 0, str.length()-1);
    return 0;
}