#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
string s;

int countPalindromes(int i, int j){

    int n = s.length();
    int count = n;

    if(i>j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j]; //memorization...as we have already calculated the value for that element
    if(i==j)
        return dp[i][j] = 1;
    else if(s[i] == s[j]){
        return dp[i][j] = countPalindromes(i+1, j) + countPalindromes(i, j-1) +1;
    }else{
        return dp[i][j] = countPalindromes(i+1, j)+ countPalindromes(i, j-1) - countPalindromes(i+1, j-1);
    }
    
}

int main(){

    cin>>s;
    memset(dp, -1, sizeof(dp));
    cout<<countPalindromes(0, s.length()-1);
}