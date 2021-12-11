#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int longestSubseq(int n, int arr[], int prev){


    if(n == 0) return 0;

    if(memo.find({n, prev}) != memo.end()) return memo[{n, prev}];

    int inc = 0, exc = 0;
    if(prev == -1 || abs(prev - arr[n-1]) == 1){
        inc = 1 + longestSubseq(n-1, arr, arr[n-1]);
    }else{
        exc = longestSubseq(n-1, arr, prev);
    }
    return memo[{n, prev}] = max(inc, exc);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<longestSubseq(n, arr, -1);
}