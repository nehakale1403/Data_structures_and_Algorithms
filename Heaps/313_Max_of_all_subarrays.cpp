#include<bits/stdc++.h>
using namespace std;

vector<int> maxinSubarray(int arr[], int n, int k){

    vector<int> res;

    priority_queue<int> heap;
    priority_queue<int> drop;
    int i=0;
    for(i=0; i<k; i++){
        heap.push(arr[i]);
    }

    res.push_back(heap.top());
    for(i=k; i<n; i++){
        if(arr[i-k] == heap.top()){
            heap.pop();
        }else{
            drop.push(arr[i-k]);
        }
        while(!drop.empty() && drop.top() == heap.top()){
            heap.pop();
            drop.pop();
        }
        heap.push(arr[i]);
        res.push_back(heap.top());
    }

    return res;
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;
    vector<int> ans =  maxinSubarray(arr, n, k);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
}