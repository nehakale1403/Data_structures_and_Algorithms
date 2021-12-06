#include<bits/stdc++.h>
using namespace std;

int getMaxGold(int M[][4], int m, int n){

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (j == m - 1) // last column
                dp[i][j] = M[i][j];
            else if (i == 0) //first row
                dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            else if (i == n - 1) // last row
                dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            else // all other cases
                dp[i][j] = M[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][0]);
    }
    return ans;
}

int main(){
    int gold[4][4] = {  {1, 3, 1, 5},
                        {2, 2, 4, 1},
                        {5, 0, 2, 3},
                        {0, 6, 1, 2}
                    };
    
    cout<<getMaxGold(gold, 4, 4);
}



// int goldtable[m][n];
//     memset(goldtable, 0, sizeof(goldtable));

//     for(int col = n-1; col >=0; col--){
        
//     }