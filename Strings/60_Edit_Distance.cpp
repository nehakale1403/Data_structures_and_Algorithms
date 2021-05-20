#include<bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

int editDistDP(string s1, string s2, int m, int n){
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j]= 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main(){

    string str1, str2;
    cin>>str1>>str2;

    cout<<editDistDP(str1, str2, str1.length(), str2.length());
}