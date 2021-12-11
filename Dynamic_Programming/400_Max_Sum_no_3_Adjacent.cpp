#include<bits/stdc++.h>
using namespace std;

int sum[1001];

int maxSum(int n, int arr[]){

    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return arr[0]+arr[1];

    if(sum[n] != -1) return sum[n]; //memoization

    return sum[n] = max({maxSum(n-1, arr), maxSum(n-2, arr) + arr[n-1], arr[n-1] + arr[n-2] + maxSum(n-3, arr)});
}

int main(){
    int n;
    cin>>n;

    memset(sum, -1, sizeof(sum));

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxSum(n, arr);
}