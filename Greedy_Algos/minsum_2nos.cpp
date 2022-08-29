#include<bits/stdc++.h>
using namespace std;

int minSum(int arr[], int n){
    priority_queue<int, vector<int>, greater<int>> minh;
    // to store the 2 numbers formed by array elements to
    // minimize the required sum
    string num1,num2;

    // Adding elements in Priority Queue
    for(int i=0; i<n; i++){
        minh.push(arr[i]);
    }

    // checking if the priority queue is non empty
    while(!minh.empty()){
        num1+=(48 + minh.top());
        minh.pop();

        if(!minh.empty()){
            num2+=(48 + minh.top());
            minh.pop();
        }
    }

    // converting string to integer
    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());

    return a+b;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minSum(arr, n)<<endl;
    return 0;
}