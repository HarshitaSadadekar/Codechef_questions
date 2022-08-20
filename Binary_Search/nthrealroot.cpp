#include<bits/stdc++.h>
using namespace std;

void findNthRoot(double num, int n){
    double low,high;

    if(num>=0 && num<=1){
        low=num;
        high=1;
    }
    else{
        low=1;
        high=num;
    }

    double epsilon = 0.00000001;
    double mid=(low+high)/2;

    while(abs(pow(mid,n)-num) >= epsilon){
        if(pow(mid,n) > num){
            high=mid;
        }
        else{
            low=mid;
        }
        mid=(low+high)/2;
    }

    cout<<mid;
}

int main(){
    double num=5;
    int n=2;
    findNthRoot(num,n);
    return 0;
}