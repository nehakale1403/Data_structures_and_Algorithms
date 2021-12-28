#include<bits/stdc++.h>
using namespace std;

int countTrees(int h){

    int dp[h+1] ={0};
    dp[0] = 1;
    dp[1] = 1;
    int p = 1e9 + 7;

    for(int i=2; i<=h; i++){
        dp[i] = (dp[i-1] * (dp[i-1] + 2 * dp[i-2])) % p; 
    }

    return dp[h];
}

int main(){
    int h;
    cin>>h;

    cout<<countTrees(h);
}