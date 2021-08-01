#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s){
    stack<int> st;

    for(int i=0; i<s.length(); i++){

        if (isdigit(s[i])) 
            st.push(s[i] - '0');
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(s[i]){
                case '+': st.push(val2+val1); break;
                case '-': st.push(val2-val1); break;
                case '*': st.push(val2*val1); break;
                case '/': st.push(val2/val1); break;
            }
        }
    }
    return st.top();
}

int main(){
    
    string s;
    cin>>s;

    cout<<evaluatePostfix(s);
}