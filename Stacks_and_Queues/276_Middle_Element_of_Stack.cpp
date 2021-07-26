#include<bits/stdc++.h>
using namespace std;

int findMid(stack<int> st, int n, int curr=0){

    if(st.empty() || curr == n)
        return -1;
    
    int x = st.top();
    st.pop();

    findMid(st, n, curr+1);

    if(curr == (n+1)/2)
        return st.top();
}

int main(){
    
    stack<int> st;
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        st.push(x);
    }

    cout<<findMid(st, n);
}