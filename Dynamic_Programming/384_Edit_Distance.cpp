#include<bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int m, int n){

    
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    }

    return dp[m][n];

}

int main(){

    string s1, s2;   
    cin>>s1>>s2;

    cout<<editDist(s1, s2, s1.length(), s2.length());
}







// #include<bits/stdc++.h>
// using namespace std;

// int editDist(string s1, string s2, int len1, int len2){

    
//     if(len1 == 0)
//         return len2;
//     if(len2 == 0)
//         return len1;
    
//     if(s1[len1-1] == s2[len2-1])
//         return editDist(s1, s2, len1-1, len2-1);
    
//     return 1 + min({editDist(s1, s2, len1, len2-1),      //insert
//                     editDist(s1, s2, len1-1, len2),      //remove
//                     editDist(s1, s2, len1-1, len2-1)});  //replace


// }

// int main(){

//     string s1, s2;   
//     cin>>s1>>s2;

//     cout<<editDist(s1, s2, s1.length(), s2.length());
// }