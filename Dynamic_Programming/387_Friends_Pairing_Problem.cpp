#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int countFriendsPairings(int n){
    
    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<=n; i++){
        dp[i] = (dp[i-1] + (i-1)*dp[i-2])%mod;
    }
    return dp[n];
}

int main(){
    
    int n;
    cin>>n;

    cout<<countFriendsPairings(n);

}


//recursive

// int countFriendsPairings(int n){
    
//     if(n <= 2)
//         return n;
    
//     return (countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2))%mod;
// }