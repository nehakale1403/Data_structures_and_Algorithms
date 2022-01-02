#include <bits/stdc++.h>
using namespace std;

int solution(int n){
    int dp[n+1][10] = {0};

    vector<int> data[10];
    data[0].insert(data[0].end(), { 0, 8 });
    data[1].insert(data[1].end(), { 1, 2, 4 });
    data[2].insert(data[2].end(), { 1, 2, 3, 5 });
    data[3].insert(data[3].end(), { 2, 3, 6 });
    data[4].insert(data[4].end(), { 1, 4, 5, 7 });
    data[5].insert(data[5].end(), { 2, 4, 5, 6, 8 });
    data[6].insert(data[6].end(), { 3, 5, 6, 9 });
    data[7].insert(data[7].end(), { 4, 7, 8 });
    data[8].insert(data[8].end(), { 5, 7, 8, 9, 0 });
    data[9].insert(data[9].end(), { 6, 8, 9 });

    for(int i = 1; i<=n; i++){
        for(int j= 0; j<=9; j++){
            if(i == 1) dp[i][j] = 1;
            else{
                for(auto prev : data[j]){
                    dp[i][j] += dp[i-1][prev];
                }
            }
        }
    }

    int sum = 0;
    for(int j = 0; j<=9; j++){
        sum += dp[n][j];
    }

    return sum;
}

int main(){
    
    int n;
    cin>>n;

    cout<<solution(n);
}