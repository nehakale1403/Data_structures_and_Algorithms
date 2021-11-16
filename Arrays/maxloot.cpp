#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int dp[n] = {0};
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    cout<<dp[n-1];
}




















// #include<bits/stdc++.h>
// using namespace std;

// int findSum(int arr[], int n){
//     int even=0;
//     int odd = 0;

//     for(int i=0; i<n; i++){
//         if(i%2 == 0){
//             even += arr[i];
//         }else{
//             odd += arr[i];
//         }
//     }

//     return max(odd, even);
// }

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i=0; i<n; i++) cin>>arr[i];

//     cout<<findSum(arr, n);
// }