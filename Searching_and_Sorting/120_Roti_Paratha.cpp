#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int par, int n, int mid){

    int time = 0;
    int paratha=0;

    for(int i=0; i<n; i++){
        time = arr[i];
        int j=2;
        while(time<=mid){
            paratha++;
            time = time+(arr[i]*j);
            j++;
        }
        if(paratha>=par)
            return 1;
    }
    return 0;
}

int minTime(int par, int n, int arr[]){
    
    int lb = 0;
    int ub = 1e8;
    int ans = 0;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(solve(arr, par, n, mid)){
            ans = mid;
            ub = mid-1;
        }else{
            lb = mid+1;
        }
    }
    return ans;
}

int main(){

    int par, n;
    cin>>par>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<minTime(par, n, arr);
}