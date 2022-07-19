//Given a positive integer, find the maximum integer possible by doing at-most K swap operations on its digits.
/* Algorithm
1) Create a global variable which will store the maximum string or number.
2) Define a recursive function that takes the string as a number, the value of k, and the current index.
3) Find the index of the maximum element in the range current index to end.
4) if the index of the maximum element is not equal to the current index then decrement the value of k.
5) Run a loop from the current index to the end of the array
6) If the ith digit is equal to the maximum element
7) Swap the ith and element at the current index and check if the string is now maximum and update the maximum string.
8) Call the function recursively with parameters: string and k.
9) Now again swap back the ith and element at the current index. 
*/

#include<bits/stdc++.h>
using namespace std;

void findMaxNum(string str, int k, string max, int ind){
    if(k==0){
        return;
    }

    int n=str.length();
    char maxm=str[ind];

    for(int j=ind+1; j<n; j++){
        if(maxm < str[j]){
            maxm=str[j];
        }
    }

    if(maxm != str[ind]){
        k--;
    }

    for(int j=n-1; j>=maxm; j--){
        if(str[j]==maxm){
            swap(str[ind], str[j]);
        }
        if(str.compare(max) > 0){
            max=str;
        }
        findMaxNum(str, k, max, ind+1);
        swap(str[ind], str[j]);
    }
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    string max=str;
    findMaxNum(str, k, max, 0);
    cout<<max<<endl;

    return 0;
}