#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n, int k){

    int dp[k+1][n];
    memset(dp, 0, sizeof(dp));

    for(int t = 1; t<=k; t++){
        int maxx = INT_MIN;

        for(int d = 1; d < n; d++){
            if(dp[t-1][d-1] - arr[d-1] > maxx) maxx = dp[t-1][d-1] - arr[d-1];

            if(maxx + arr[d] > dp[t][d-1]){
                dp[t][d] = maxx + arr[d];
            }else{
                dp[t][d] = dp[t][d-1];
            }
        }
    }
    return dp[k][n-1];
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<maxProfit(arr,n, k);
}