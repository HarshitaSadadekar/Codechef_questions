#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[], int n){
    vector<int> left;
    stack<pair<int,int>> s;
    int pseudoindex = -1;

    for(int i=0; i<n; i++){
        if(s.size() == 0){
            left.push_back(pseudoindex);
        }
        else if(s.size() > 0 && s.top().first > arr[i]){
            left.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    return left;
}

vector<int> nearestGreaterToRight(int arr[], int n){
    vector<int> right;
    stack<pair<int,int>> s1;
    int pseudoindex = n+1;

    for(int i=0; i<n; i++){
        if(s1.size() == 0){
            right.push_back(pseudoindex);
        }
        else if(s1.size() > 0 && s1.top().first > arr[i]){
            right.push_back(s1.top().second);
        }
        else if(s1.size() > 0 && s1.top().first <= arr[i]){
            while(s1.size() > 0 && s1.top().first <= arr[i]){
                s1.pop();
            }
            if(s1.size() == 0){
                right.push_back(-1);
            }
            else{
                right.push_back(s1.top().second);
            }
        }
        s1.push({arr[i], i});
    }
    return right;
}

int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    vector<int> left = nearestGreaterToLeft(a,N);
    vector<int> right = nearestGreaterToRight(a,N);

    vector<int> width;
    vector<int> area;
    for(int k=0; k<N; k++){
        width[k] = right[k] - left[k] -1;
    }
    for(int k=0; k<N; k++){
       area[k] =a[k] * width[k];
    }
    cout<<*max_element(area.begin(), area.end());
    return 0;
}