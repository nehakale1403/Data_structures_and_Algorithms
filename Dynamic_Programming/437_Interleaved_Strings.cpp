#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool solve(string a, string b, string c, int n, int m, int l){

    if(l<=0) return 1;

    if(dp[n][m]!=-1)return dp[n][m];

    int x = 0, y = 0;
    if(n-1 >= 0 && a[n-1] == c[l-1])
        x = solve(a, b, c, n-1, m, l-1);
    if(m-1 >= 0 && b[m-1] == c[l-1])
        y = solve(a, b, c, n, m-1, l-1);
    
    return dp[n][m] = x|y;
}

bool isInterleave(string a, string b, string c){
    memset(dp,-1,sizeof(dp));

    return solve(a, b, c, a.length(), b.length(), c.length());
}

int main(){
    
    string a, b, c;
    cin>>a>>b>>c;

    cout<<isInterleave(a, b, c);
}