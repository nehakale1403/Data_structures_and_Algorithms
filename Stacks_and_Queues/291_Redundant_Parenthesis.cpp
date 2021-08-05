#include<bits/stdc++.h>
using namespace std;

bool redundantParenthesis(string s){

    int n = s.length();

    stack<char> st;

    for(int i=0; i<n; i++){
        
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }else if(s[i] == ')'){

            if(st.top() == '('){
                return true;
            }
            while(!st.empty() && (st.top()!='(')){
                st.pop();
            }
               
            st.pop();
            if(!st.empty() && (st.top() == '('))
                return true;
        }
    }
    return false;
}

int main(){

    string s;
    cin>>s;

    if(redundantParenthesis(s))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}