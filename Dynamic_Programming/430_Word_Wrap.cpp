#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int solve(int arr[], int k, int k1, int n, int i){
    if(dp[i][k1] != -1) return dp[i][k1];
    if(i == n-1){
        if(k1 > arr[i])
            return 0;
        else
            return k1 * k1;
    }else if(k1 == k){
        return dp[i][k1] = solve(arr, k, k-arr[i], n, i+1);
    }else{
        if(k1 > arr[i])
            return dp[i][k1] = min(k1*k1 + solve(arr, k, k, n, i), solve(arr, k, k1-arr[i]-1, n, i+1));
        else
            return dp[i][k1] = k1*k1 + solve(arr, k, k, n, i);
    }
}

int wordWrap(int arr[], int n, int k){
    memset(dp,-1,sizeof(dp));
    return solve(arr, k, k, n, 0);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<wordWrap(arr, n, k);
}