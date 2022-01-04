#include <bits/stdc++.h>
using namespace std;

int dp[201][201][2];

int solve(string s, int i, int j, bool tf){
       if(i>j) return 0;
       if(i==j){
           if(tf){
               return s[i]=='T';
           } 
           else return s[i]=='F';
       }
       if(dp[i][j][tf]!=-1) return dp[i][j][tf];
       int ans = 0;
       for(int k = i+1; k<j; k=k+2){
           int lt = solve(s,i,k-1,1);
           int lf = solve(s,i,k-1,0);
           int rt = solve(s,k+1,j,1);
           int rf = solve(s,k+1,j,0);
           
           if(s[k]=='|'){
               if(tf)
               ans += lt*rt + lt*rf + lf*rt;
               else
               ans += lf*rf;
           }
           else if(s[k]=='&'){
               if(tf)
               ans += rt*lt;
               else
               ans += rt*lf + lt*rf + rf*lf;
           }
           else{
               if(tf)
               ans += lt*rf + rt*lf;
               else
               ans += rt*lt + rf*lf;
           }
       }
       return dp[i][j][tf] = ans%1003;
   }

int countWays(string s, int n){

    memset(dp,-1,sizeof(dp));
    return solve(s,0,n-1,true);

    

    // int dpt[n][n];
    // int dpf[n][n];

    // for(int g = 0; g<n; g++){
    //     for(int i=0, j = g; j<n; i++, j++){
    //         if(g == 0){
    //             char ch = s[i];

    //             if(ch == 'T'){
    //                 dpt[i][j] = 1;
    //                 dpf[i][j] = 0;
    //             }else{
    //                 dpt[i][j] = 0;
    //                 dpf[i][j] = 1;
    //             }
    //         }else{
    //             for(int k = i; k < j; k++){
    //                 char oprtr = s[k];

    //                 int ltc = dpt[i][k];
    //                 int rtc = dpt[k+1][j];
    //                 int lfc = dpf[i][k];
    //                 int rfc = dpf[k+1][j];

    //                 if(oprtr == '&'){
    //                     dpt[i][j] = ltc * rtc;
    //                     dpf[i][j] = lfc * rtc + ltc * rfc + lfc*rfc;
    //                 }else if(oprtr == '|'){
    //                     dpt[i][j] = ltc * rtc + lfc * rtc + ltc * rfc;
    //                     dpf[i][j] = lfc * rfc;
    //                 }else{
    //                     dpt[i][j] = ltc * rfc + lfc * rtc;
    //                     dpf[i][j] = lfc * rfc + ltc * rtc;
    //                 }
    //             }
    //         }
    //     }
    // }

    // return dpt[0][n-1];
}

int main(){
    
    string s;
    cin>>s;

    cout<<countWays(s, s.length());
}