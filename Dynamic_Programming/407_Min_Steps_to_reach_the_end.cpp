#include<bits/stdc++.h>
using namespace std;

int minSteps(int arr[], int n){

    int dp[n];
    memset(dp, -1, sizeof(dp));
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        int steps = arr[i];
        int min_val = INT_MAX;
        for(int j=1; j<=steps && i+j < n; j++){
            if(dp[i+j] != -1 && dp[i+j] < min_val)
                min_val = dp[i+j];
        }
        if(min_val != INT_MAX)
            dp[i] = 1 + min_val;
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<minSteps(arr, n);
}


// int minSteps(int arr[], int n){

//     if(n == 1) 
//         return 0;
//     else if(arr[0] == 0) 
//         return -1;
//     else{
//         int jumps = 1;
//         int steps = arr[0];
//         int max_reach = arr[0];
//         for(int i=1; i<n; i++){
//             if(i == n-1){
//                 return jumps;
//             }
//             steps--;
//             max_reach = max( max_reach,i + arr[i]);
//             if(steps == 0){
//                 jumps++;
//                 if(i >= max_reach)
//                     return -1;
//                 steps = max_reach-1;
//             }
            
//         }
//     }
// }