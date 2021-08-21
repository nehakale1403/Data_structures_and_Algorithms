#include<bits/stdc++.h>
using namespace std;

int maxProductSubset(int arr[], int n){

    if(n==1)
        return arr[0];
    
    int max_neg =INT_MIN;

    int count_neg=0;
    int count_zero = 0;
    int prod = 1;

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            count_zero++;
            continue;
        }

        if(arr[i]<0){
            count_neg++;
            max_neg = max(max_neg, arr[i]);
        }
        prod = prod * arr[i];
    }

    if(count_zero == n)
        return 0;
    
    if(count_neg & 1){
        if(count_neg == 1 && count_zero > 0 && (count_zero + count_neg == 1)){
            return 0;
        }
        prod = prod / max_neg;
    }
    return prod;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxProductSubset(arr, n);
}