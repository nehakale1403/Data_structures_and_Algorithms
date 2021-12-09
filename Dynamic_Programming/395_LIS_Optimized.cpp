#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){

    int dp[n] = {0};

    int overallMax = 0;

    dp[0] = 1;

    for(int i=1; i<n; i++){
        int maxx = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                if(dp[j] > maxx) maxx = dp[j];
            }
        }
        dp[i] = maxx+1;
        if(dp[i] > overallMax)
            overallMax = dp[i];
    }

    return overallMax;
}

int main(){
    
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<lis(arr, n);
}