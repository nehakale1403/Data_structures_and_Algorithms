#include<bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q, int k, int n){
    stack<int> st;

    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0; i<n-k; i++){
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

    int k;
    cin>>k;

    reverseK(q, k, n);

    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}