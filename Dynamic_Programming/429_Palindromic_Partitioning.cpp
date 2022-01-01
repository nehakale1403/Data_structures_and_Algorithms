#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int i, int j){

    while(i < j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minPalPartition(string s, int i, int j){

    if(i >= j || isPalindrome(s, i, j))
        return 0;

    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = INT_MAX;
    int count;

    for(int k = i; k<j; k++){
        count = minPalPartition(s, i, k) + minPalPartition(s, k+1, j) + 1;

        ans = min(ans, count);
    }
    return dp[i][j] = ans;
}

int main(){
    
    string s;
    cin>>s;

    memset(dp, -1, sizeof(dp));

    cout<<minPalPartition(s, 0, s.length()-1);

}