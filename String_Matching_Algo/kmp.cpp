#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char pat[], int m, int lps[]){
    // length of the previous longest prefix suffix
    int len=0; 
    // lps[0] is always 0
    lps[0]=0;

    // the loop calculates lps[i] for i = 1 to m-1
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len != 0){
                len= lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMPSearch(char pat[], char txt[], int n, int m){
    //n for txt and m for pat
    int lps[m];
    computeLPSArray(pat,m,lps);

    int i=0,j=0; //i for txt[], j for pat[]
    while(i<n){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==m){
            cout<<"Pattern found at index"<<" "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && pat[j] != txt[i]){
            if(j != 0){
                j=lps[j-1];
            }
            else{
                i=i+1;
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
    KMPSearch(pat,txt,N,M);
    return 0;
}