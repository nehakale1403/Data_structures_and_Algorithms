#include<bits/stdc++.h>
using namespace std;

stack<int> insertAtBottom(stack<int> st,int n){
    stack<int> temp;

    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(n);

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    int n;
    cin>>n;
    stack<int> ans = insertAtBottom(st, n);

    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
}