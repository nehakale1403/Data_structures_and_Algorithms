#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

int mincount(int arr[], int i, int j, int k){

    if(i>=j) return 0;
    else if(arr[j] - arr[i] <= k) return 0;
    else if(dp[i][j] != -1) return dp[i][j];
    else{
        return 1 + min(mincount(arr, i+1, j, k), mincount(arr, i, j-1, k));
    }
}

int minRemovals(int n, int arr[], int k){

    sort(arr, arr+n);
    memset(dp, -1, sizeof(dp));
    if(n == 1) return 0;
    else return mincount(arr, 0, n-1, k);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;
    cout<<minRemovals(n, arr, k);
}