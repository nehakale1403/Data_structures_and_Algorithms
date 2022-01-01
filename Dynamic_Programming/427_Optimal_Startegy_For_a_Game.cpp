#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int maximumAmount(int arr[], int i, int j){

    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //while the other player is playing, he will also take the higher amt coin
    //we will consider min of it
    int left = arr[i] + min(maximumAmount(arr, i+2, j), maximumAmount(arr, i+1, j-1));
    int right = arr[j] + min(maximumAmount(arr, i+1, j-1), maximumAmount(arr, i, j-2));

    return dp[i][j] = max(left, right);
    
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    memset(dp, -1, sizeof(dp));

    cout<<maximumAmount(arr,0, n-1);
}