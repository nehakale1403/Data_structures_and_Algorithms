#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int req, int mid){

    int sum = 0;
    for(int i=0; i<n; i++){
        
        if(arr[i]>mid){
            sum+=(arr[i]-mid);
        }
    }
    if(sum>=req)
        return true;
    else
        return false;
}

int setHeight(int arr[], int n, int req){

    
    int lb=0;
    int ub = *max_element(arr, arr+n);
    int ans=0;

    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(solve(arr, n, req, mid)){
            ans = mid;
            lb = mid+1;
        }else{
            ub = mid-1;
        }
    }
    return ans;
}

int main(){

    int n, m;
    cin>>n>>m;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<setHeight(arr, n, m);
}