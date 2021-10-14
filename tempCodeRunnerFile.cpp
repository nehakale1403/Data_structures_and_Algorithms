#include<bits/stdc++.h>
using namespace std;

bool parenthesisMatching(string s){
    int n = s.length();
    stack<char> st;
    for(int i=0; i<n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
            st.push(s[i]);
            continue;
        }else{
            if(st.empty())
                return false;

            if(s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }    
            }
            if(s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }    
            }
            if(s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }    
            }
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int main(){
    string s;
    cin>>s;

    if(parenthesisMatching(s)){
        cout<<"Yes"<<endl;
    }else
        cout<<"No"<<endl;
}