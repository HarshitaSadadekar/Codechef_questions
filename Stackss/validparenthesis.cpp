#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            switch(s[i]) {
                case '(' :
                    st.push(s[i]);
                    break;
                case '{' :
                    st.push(s[i]);
                    break;
                case '[' :
                    st.push(s[i]);
                    break;
                case ')' :
                    if(st.empty() || st.top() != '('){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                    break;
                case '}' :
                    if(st.empty() || st.top() != '{'){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                    break;
                case ']' :
                    if(st.empty() || st.top() != '['){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                    break;
            }
        }
        return st.empty();
}

int main(){
    string S;
    cin>>S;
    cout<<isValid(S);
    return 0;
}