#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int lps(string s, int i, int j){

    if(i == j) return 1;

    if(s[i] == s[j] && i + 1 == j) return 2;

    if(memo.find({i, j}) != memo.end()) return memo[{i, j}];

    if(s[i] == s[j]) return memo[{i, j}] = lps(s, i+1, j-1) + 2;

    return memo[{i, j}] = max(lps(s, i, j-1), lps(s, i+1, j));

}

int main(){

    string s;
    cin>>s;

    cout<<lps(s, 0, s.length());
}