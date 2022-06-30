//Finding minimum element using extra space
#include<bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int b){
    s.push(b);
    if(ss.size()==0 || ss.top() >= b){
        ss.push(b);
    }
}

int pop(){
    if(s.size()==0){
        return -1;
    }
    int ans = s.top();
    s.pop();
    if(ss.top()==ans){ //to check if the element we are popping from 's' stack is min element then we need to pop from 'ss' stack as well.
        ss.pop();
    }
}

int getMin(){
    if(ss.size() == 0){
        return -1;
    }
    else{
        return ss.top();
    }
}

int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    return 0;
}


//without using extra space

int minEle;

int getMin(){
    if(s.size()==0){
        return -1;
    }
    return minEle;
}

void push(int b){
    if(s.size()==0){
        s.push(b);
        minEle=b;
    }
    else{
        if(b>=minEle){
            s.push(b);
        }
        else if(b<minEle){
            s.push(2*b - minEle);
            minEle=b;
        }
    }
}

void pop(){
    if(s.size()==0){
        return -1;
    }
    else{
        if(s.top() >= minEle){
            s.pop();
        }
        else if(s.top() < minEle){
            minEle = 2*minEle - s.top();
            s.pop();
        }
    }
}

int top(){
    if(s.size()==0){
        return -1;
    }
    else{
        if(s.top() >= minEle){
            return s.top();
        }
        else if(s.top() < minEle){
            return minEle;
        }
    }
}