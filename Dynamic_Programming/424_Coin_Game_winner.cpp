#include <bits/stdc++.h>
using namespace std;

map<int, bool> memo;

bool findWinner(int n, int x, int y){

    if(n == x || n == y) return 1;
    if(n < 0) return 0;

    if(memo.find(n) != memo.end()) return memo[n];

    return memo[n] = n-1>=0?findWinner(n-1, x, y):0 || n-x >= 0 ?findWinner(n-x, x, y):0|| n-y >= 0 ?findWinner(n-y, x, y):0;
}

int main(){
    int n, x, y;
    cin>>n>>x>>y;

    cout<<findWinner(n, x, y);
}

// #include <bits/stdc++.h>
// using namespace std;
 
// // To find winner of game
// bool findWinner(int x, int y, int n)
// {
//     // To store results
//     int dp[n + 1];
 
//     // Initial values
//     dp[0] = false;
//     dp[1] = true;
 
//     // Computing other values.
//     for (int i = 2; i <= n; i++) {
 
//         // If A losses any of i-1 or i-x
//         // or i-y game then he will
//         // definitely win game i
//         if (i - 1 >= 0 and !dp[i - 1])
//             dp[i] = true;
//         else if (i - x >= 0 and !dp[i - x])
//             dp[i] = true;
//         else if (i - y >= 0 and !dp[i - y])
//             dp[i] = true;
 
//         // Else A loses game.
//         else
//             dp[i] = false;
//     }
 
//     // If dp[n] is true then A will
//     // game otherwise  he losses
//     return dp[n];
// }
 
// // Driver program to test findWinner();
// int main()
// {
//     int x = 2, y = 3, n = 1;
//     if (findWinner(x, y, n))
//         cout << 'A';
//     else
//         cout << 'B';
 
//     return 0;
// }