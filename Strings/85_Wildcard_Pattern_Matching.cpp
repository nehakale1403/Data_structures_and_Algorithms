#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int solve(string p, string s, int i, int j){

    //when both the iterators reach at the front without any problem then returning 1
    if(i==-1 && j==-1)
        return 1;

    //when the string length gets over, we will check if pattern is having only * at the front
    //if yes then returning 1 else 0
    if(j==-1){
        for(int k=0; k<i; k++){
            if(p[k] != '*')
                return 0;
        }
        return 1;
    }

    //if the string gets over and pattern is still left
    if(i==-1)
        return 0;

    //memoization
    if(dp[i][j] != -1)
        return dp[i][j];
    
    //moving one character back in both cases
    if((p[i] == s[j]) || (p[i]=='?'))
        return dp[i][j] = solve(p, s, i-1, j-1);
    
    //when there is star, there are 2 possibilities
    //1. it replaces null
    //2. it replaces 2 or more characters
    if(p[i] == '*'){
        int op1 = solve(p, s, i-1, j);
        int op2 = solve(p, s, i, j-1);
        //if any one of it is true, then dp[i][j] is true
        return dp[i][j] = op1 or op2;
    }
    //if none of the conditions is satisfied, fill dp[i][j] as false
    return dp[i][j] = 0;

}



int main(){

    string str, pattern;
    cin>>str>>pattern;

    memset(dp, -1, sizeof(dp));

    int x = solve(pattern, str, pattern.length()-1, str.length()-1);

    if(x==1)
        cout<<"Yes";
    else
        cout<<"No";

}