#include<bits/stdc++.h>
using namespace std;

int catalan(int n){

    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    cout<<catalan(n);
}



// int catalan(int n){

//     if(n <= 1) return 1;

//     int res = 0;
//     for(int i=0; i<=n-1; i++){
//         res += catalan(i) * catalan(n-i-1);
//     }
//     return res;
// }