#include<bits/stdc++.h>
using namespace std;

int mini = INT_MAX;

void push(stack<int> &st, int ele){
    if(ele<mini)
        mini = ele;

    st.push(ele);

}

int main(){
    
    stack<int> st;
    int n;
    cin>>n;

    push(st, 1);
    push(st, 2);

    cout<<mini;
}