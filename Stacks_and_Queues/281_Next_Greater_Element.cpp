#include<bits/stdc++.h>
using namespace std;

void printNextGreatestEle(int arr[], int n){
    
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && st.top()<arr[i]){
            cout<<arr[i]<<" ";
            st.pop();
        }
        st.push(arr[i]);
    }

    while(!st.empty()){
        cout<<"-1";
        st.pop();
    }
        
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    printNextGreatestEle(arr, n);
}