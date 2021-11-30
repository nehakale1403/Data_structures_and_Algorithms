#include<bits/stdc++.h>
using namespace std;

int countChange(int target, int m, int arr[]){

    int dp[target+1] = {0};
    dp[0] = 1;
    for(int i=0; i<m; i++){
        for(int j=arr[i]; j<target+1; j++){
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main(){
    int n, m;
    cin>>n>>m;

    int arr[m];
    for(int i=0; i<m; i++) cin>>arr[i];

    cout<<countChange(n, m, arr);
}

// #include<bits/stdc++.h>
// using namespace std;

// int countChange(int target, int m, int arr[], int idx, map<int, int> &memo){

//     if(memo.find(target) != memo.end()) return memo[target];

//     int count=0;
//     if(target == 0) return 1;
//     if(target < 0) return 0;
//     if(m<=0 && target>=1) return 0;

//     for(int i=idx; i<m; i++){
//         count += countChange(target-arr[i], m, arr, i, memo);
//     }

//     memo[target] = count;
//     return count;
// }

// int main(){
//     int n, m;
//     cin>>n>>m;

//     int arr[m];
//     for(int i=0; i<m; i++) cin>>arr[i];

//     map<int, int> memo;
//     cout<<countChange(n, m, arr, 0, memo);
// }

