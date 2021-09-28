#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cin>>k;
    
    priority_queue<int> heap;

    for(int i=0; i<n; i++){
        heap.push(arr[i]);
    }

    while(k--){
        cout<<heap.top()<<" ";
        heap.pop();
    }
}