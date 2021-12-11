#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int productK(int n, int arr[], int k, int prod){

    if(n == 0 && prod < k && 0 <= prod) return 1;

    if(n == 0 || prod >= k) return 0;

    if(memo.find({n, prod}) != memo.end()) return memo[{n, prod}];

    return memo[{n, prod}] = productK(n-1, arr, k, prod) + productK(n-1, arr, k, prod<0 ? arr[n-1] : prod * arr[n-1]);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<productK(n, arr, k, -1);
}