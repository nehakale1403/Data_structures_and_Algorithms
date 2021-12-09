// https://www.youtube.com/watch?v=0Ql40Llp09E

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){

    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1] = {0};

    for(int i= m-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[j+1][i]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    
    string s1, s2;

    cin>>s1>>s2;

    cout<<lcs(s1, s2);
}