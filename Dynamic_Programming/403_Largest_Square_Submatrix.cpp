#include<bits/stdc++.h>
using namespace std;

int maxSquare(int m, int n, vector<vector<int>> mat){

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int ans = INT_MIN;

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            
            if(i == n-1 && j == m-1){
                dp[i][j] = mat[i][j];
            }else if(i == n-1){ 
                dp[i][j] = mat[i][j];
            }else if(j == m-1){
                dp[i][j] = mat[i][j];
            }else{
                if(mat[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) + 1;

                if(dp[i][j] > ans) ans = dp[i][j];
            }
        }
    }

    return ans;
    
}

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n, 0));
    for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];

    cout<<maxSquare(m, n, mat);
}