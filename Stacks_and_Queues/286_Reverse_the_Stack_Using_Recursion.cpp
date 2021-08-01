#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int n){

    if(st.empty()){
        st.push(n);
        return;
    }
        
    int topele = st.top();
    st.pop();
    insertAtBottom(st, n);

    st.push(topele);
}

void reverseSt(stack<int> &st){

    if(st.empty())
        return;

    int ele = st.top();
    st.pop();

    reverseSt(st);
    insertAtBottom(st, ele);
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    reverseSt(st);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}