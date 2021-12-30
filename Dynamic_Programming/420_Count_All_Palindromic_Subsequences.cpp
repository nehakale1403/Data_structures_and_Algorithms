#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int mod = 1e9 + 7;

int countPS(string s, int i, int j){

    if(i > j) return 0;
    if(i == j) return 1;
    if(memo.find({i, j}) != memo.end()) return memo[{i, j}];
    if(s[i] == s[j]) 
        return memo[{i, j}] = (1 + countPS(s, i+1, j) + countPS(s, i, j-1)) % mod;
    else
        return memo[{i, j}] = (mod + countPS(s, i+1, j) + countPS(s, i, j-1) - countPS(s, i+1, j-1)) % mod;
}

int main(){

    string s;
    cin>>s;

    cout<<countPS(s, 0, s.length()-1);
}