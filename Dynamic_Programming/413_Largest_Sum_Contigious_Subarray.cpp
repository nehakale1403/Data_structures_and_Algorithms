#include<bits/stdc++.h>
using namespace std;

int lscs(int arr[], int n){

    int max_global=arr[0], max_curr=arr[0];

    for(int i=1; i<n; i++){
        max_curr = max(arr[i], max_curr + arr[i]);
        max_global = max(max_global, max_curr);
    }
    return max_global;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<lscs(arr, n);
}