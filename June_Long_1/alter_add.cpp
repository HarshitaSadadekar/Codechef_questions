#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	   int a,b; cin>>a>>b;
	   int i=1;
	   while(a<b){
	    if(i%2 != 0){
	        a+=1;
	    }  
	    else if(i%2 == 0){
	        a+=2;
	    }
	    i++;
		}
	   if(a==b){
	        cout<<"Yes"<<endl;
	    }
	   else if(a>b){
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
