#include<bits/stdc++.h>
using namespace std;

void firstNegativeInWindow(int arr[], int n, int k){

    deque<int> dq;

    int i;
    for(i=0; i<k; i++)
        if(arr[i]<0)
            dq.push_back(i);
    
    for(; i<n; i++){
        if(!dq.empty())
            cout<<arr[dq.front()]<<" ";
        else
            cout<<"0"<<" ";

        while(!dq.empty() && (dq.front()<i-k+1))
            dq.pop_front();
        
        if(arr[i]<0)
            dq.push_back(i);
    }
    if(!dq.empty())
        cout<<arr[dq.front()]<<" ";
    else
        cout<<"0"<<" ";
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    firstNegativeInWindow(arr, n, k);
}