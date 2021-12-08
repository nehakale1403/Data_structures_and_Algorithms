#include<bits/stdc++.h>
using namespace std;

int dp[1001] = {0};

int maximizeTheCuts(int n, int x, int y, int z){
    if(n == 0)
        return 0;

    if(dp[n] != 0)
        return dp[n];

    int x1 = INT_MIN, y1 = INT_MIN, z1 = INT16_MIN;

    if(x<=n)
        x1 = maximizeTheCuts(n - x, x, y, z);
    
    if(y<=n)
        y1 = maximizeTheCuts(n - y, x, y, z);
    
    if(z<=n)
        z1 = maximizeTheCuts(n - z, x, y, z);

    return dp[n] = 1 + max({x1, y1, z1});
}

int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;

    cout<<maximizeTheCuts(n, x, y, z);
}





//recursive approach

// int maximizeTheCuts(int n, int x, int y, int z){
//     if(n == 0)
//         return 0;

//     int x1 = INT_MIN, y1 = INT_MIN, z1 = INT16_MIN;

//     if(x<=n)
//         x1 = maximizeTheCuts(n - x, x, y, z);
    
//     if(y<=n)
//         y1 = maximizeTheCuts(n - y, x, y, z);
    
//     if(z<=n)
//         z1 = maximizeTheCuts(n - z, x, y, z);

//     return 1 + max({x1, y1, z1});
// }