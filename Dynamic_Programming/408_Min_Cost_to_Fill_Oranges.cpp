#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int minCost(int cost[], int n, int w){

    if(n == -1 && w == 0) return 0;
    if(n == -1) return 1e9;
    if(w == 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(n+1 > w || cost[n] == -1) return dp[n][w] = minCost(cost, n-1, w);
    else return dp[n][w] = min(minCost(cost, n-1, w), cost[n] + minCost(cost, n-1, w - (n+1))); 
}

int main(){
    int n;
    cin>>n;

    int cost[n];
    for(int i=0; i<n; i++) cin>>cost[i];

    int w;
    cin>>w;

    memset(dp, -1, sizeof(dp));

    int res = minCost(cost, n, w);
    if( res == 1e9) cout<<"-1"<<endl;
    else cout<<res<<endl;
}