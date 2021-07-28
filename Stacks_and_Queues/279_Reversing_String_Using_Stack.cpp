#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    int n = s.length();

    stack<char> st;
    for(int i=0; i<n; i++)
        st.push(s[i]);
    
    string res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main(){
    string s;
    cin>>s;

    cout<<reverse(s);
}