#include<bits/stdc++.h>
using namespace std;

bool validatePermutation(int pushed[], int popped[], int n){

    stack<int> st;


    int i=0, j=0;
    for(int i=0; i<n; i++){
        st.push(pushed[i]);
        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
    return j == n;
        
}

int main(){
    int n;
    cin>>n;

    int pushed[n];
    int popped[n];

    for(int i=0; i<n; i++)
        cin>>pushed[i];

    for(int i=0; i<n; i++)
        cin>>popped[i];

    if(validatePermutation(pushed, popped, n))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}