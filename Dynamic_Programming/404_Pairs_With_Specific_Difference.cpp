#include<bits/stdc++.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k){

    sort(arr, arr+n);
    int sum=0;
    int i=n-1;
    while(i>=0){
        if(arr[i] - arr[i-1] < k && i > 0){
            sum += arr[i] + arr[i-1];
            i -= 2;
        }else{
            i--;
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;
    cout<<maxSumPairWithDifferenceLessThanK(arr, n, k);
}