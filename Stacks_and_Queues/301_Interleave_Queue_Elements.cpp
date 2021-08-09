#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q, int n){
    
    stack<int> st;

    int halfsize = n/2;

    for(int i=0; i<halfsize; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0; i<halfsize; i++){
        q.push(q.front());
        q.pop();
    }
    for(int i=0; i<halfsize; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}


int main(){
    int n;
    cin>>n;

    queue<int> q;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q.push(x);
    }

    interleaveQueue(q, n);

    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}