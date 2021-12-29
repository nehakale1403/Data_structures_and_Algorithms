#include <bits/stdc++.h>
using namespace std;

int isSubsetSum(int arr[], int n, int sum){

    if(sum == 0) return 1;

    else if(n == 0 || sum <= 0) return 0;

    return isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
}

int equalPartition(int arr[], int n){

    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    if(sum % 2 != 0) return 0;
    
    return isSubsetSum(arr, n, sum/2);
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<equalPartition(arr, n);
}