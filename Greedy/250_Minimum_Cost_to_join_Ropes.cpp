#include<bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n){

    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

    int cost = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        cost += first + second;
        pq.push(first+second);
    }

    return cost;

}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<minCost(arr, n);
}