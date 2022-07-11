#include<bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet 
#define d 256

/* pat -> pattern 
    txt -> text 
    q -> A prime number 
*/
void search(char pat[], char txt[], int q, int n, int m){
    //n for txt and m for pat
    int i,j,h=1;
    int p=0; // hash value for pattern 
    int t=0; // hash value for txt 

    for(i=0; i<m-1; i++){
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for(i=0; i<m; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for(i=0; i<=n-m; i++){
        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters one by one
        if(p==t){
            /* Check for characters one by one */
            for(j=0; j<m; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }
        if(i<n-m){
            t = (d*(t-txt[i]*h) + txt[i+m])%q;

            if(t<0){
                t=(t+q);
            }
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    char txt[N], pat[M];
    for(int i=0; i<N; i++){
        cin>>txt[i];
    }
    for(int i=0; i<M; i++){
        cin>>pat[i];
    }
    int q=INT_MAX;
    search(pat,txt,q, N, M);
    return 0;
}