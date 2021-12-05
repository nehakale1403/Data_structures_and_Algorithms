#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int n, int arr[], int sum){

    if(sum == 0) return 1;
    else if(n == 0 || sum < 0) return 0;

    return isSubsetSum(n-1, arr, sum-arr[n-1]) || isSubsetSum(n-1, arr, sum); //include or exclude to make sum
}


bool subsetSum(int n, int arr[]){

    int sum =0;
    for(int i=0; i<n; i++){
        sum +=arr[i];
    }

    if(sum%2 != 0)
        return 0;
    
    return isSubsetSum(n, arr, sum/2);

}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    
    cout<<subsetSum(n, arr);
}