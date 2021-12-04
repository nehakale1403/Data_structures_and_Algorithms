#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+2;

int dp[N][N];

int knapsack01(int n, int w, int wt[], int profit[]){

    if(w == 0 || n==0) return 0;

    if(dp[n][w] != -1)
        return dp[n][w];

    int inc=0, exc=0, ans = 0;

    if(wt[n-1] > w)
        dp[n][w] = knapsack01(n-1, w, wt, profit);

    dp[n][w] = max(knapsack01(n-1, w, wt, profit), knapsack01(n-1, w-wt[n-1], wt, profit) + profit[n-1]); 
    return dp[n][w];
}

int main(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = -1;
        }
    }
    int n, w;
    cin>>n>>w;
    int weights[n];
    int profit[n];
    for(int i=0; i<n; i++) cin>>weights[i];
    for(int i=0; i<n; i++) cin>>profit[i];

    cout<<knapsack01(n, w, weights, profit);
}

int fact(int n){
    if(memo.find(n) != memo.end())
        return memo[n];
    if(n == 1)
        return 1;
    memo[n] = n * fact(n-1);
    return memo[n];
}