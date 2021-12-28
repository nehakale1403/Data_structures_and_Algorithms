#include<bits/stdc++.h>
using namespace std;

int sscs(int arr[], int n){

    int min_global=arr[0], min_curr=arr[0];

    for(int i=1; i<n; i++){
        min_curr = min(arr[i], min_curr + arr[i]);
        min_global = min(min_global, min_curr);
    }
    return min_global;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<sscs(arr, n);
}