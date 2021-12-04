#include<bits/stdc++.h>
using namespace std;



int computenCr(int n, int r){
    if(n < r) return 0;
    if(n-r < r) r = n-r;

    int mod = 1000000007;

    int dp[r+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j= min(r, i); j>0; j--){
            dp[j] = (dp[j] + dp[j-1])%mod;
        }
    }
    return dp[r];
}

int main(){

    int n, r;
    cin>>n>>r;

    cout<<computenCr(n, r);
}


//memoization


// #include<bits/stdc++.h>
// using namespace std;

// map<int, long long int> memo;

// long long int fact(int n){
//     if(memo.find(n) != memo.end())
//         return memo[n];
//     if(n == 1)
//         return 1;
//     memo[n] = n * fact(n-1);
//     cout<<n<<" "<<memo[n]<<endl;
//     return memo[n];
// }

// int computenCr(int n, int r){
//     if(n == r)
//         return 1;
//     if(n < r)
//         return 0;
    
//     return fact(n)/(fact(n-r) * fact(r));
// }

// int main(){

//     int n, r;
//     cin>>n>>r;

//     cout<<computenCr(n, r);
// }