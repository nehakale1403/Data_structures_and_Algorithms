#include<bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n, int m){

    int ans=INT_MAX;

    sort(arr, arr+n);
    for(int i=0; i<=n-m; i++){
        int first = arr[i];
        int second = arr[i+m-1];
        ans = min(ans, second-first);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    int m;
    cin>>m;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<minDifference(arr, n, m);
}