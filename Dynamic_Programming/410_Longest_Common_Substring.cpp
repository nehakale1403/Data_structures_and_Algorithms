#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int longestCommonSubstr(string s1, string s2, int n, int m, int count){

    if(memo.find({n, m}) != memo.end()) 
        return memo[{n, m}];
    else if(n == 0 ||m == 0)
        return count;
    else if(s1[n-1] == s2[m-1]){
        count = longestCommonSubstr(s1, s2, n-1, m-1, count+1);
    }else{
        count = max({count, longestCommonSubstr(s1, s2, n-1, m, 0), longestCommonSubstr(s1, s2, n, m-1, 0)});
    }

    return memo[{n, m}] = count;
}

int main(){
    
    string s1, s2;
    cin>>s1>>s2;

    cout<<longestCommonSubstr(s1, s2, s1.length(), s2.length(), 0);
}