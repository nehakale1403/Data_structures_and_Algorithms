#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int x){

    if(st.empty() || x > st.top()){
        st.push(x);
    }else{
        int temp = st.top();
        st.pop();
        sortedInsert(st, x);
        st.push(temp);
    }
}

void sortSt(stack<int> &st){

    if(!st.empty()){
        int x = st.top();
        st.pop();
        sortSt(st);
        sortedInsert(st, x);
    }
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(9);
    st.push(4);

    sortSt(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}