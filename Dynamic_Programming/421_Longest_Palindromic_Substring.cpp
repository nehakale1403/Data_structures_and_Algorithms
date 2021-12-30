#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int longestPalindrome(string s, int i, int j, int count){

    if(i>j) return count;

    if(i == j) return count+1;

    if(memo.find({i, j}) != memo.end()) return memo[{i, j}];

    if(s[i] == s[j]){
        count = longestPalindrome(s, i+1, j-1, count+2);
        return memo[{i, j}] = max({count, longestPalindrome(s, i+1, j, 0), longestPalindrome(s, i, j-1, 0)});
    }else{
        return memo[{i, j}] = max(longestPalindrome(s, i+1, j, 0), longestPalindrome(s, i, j-1, 0));
    }
}

int main(){

    string s;
    cin>>s;
    
    cout<<longestPalindrome(s, 0, s.length(), 0);
}