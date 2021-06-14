#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int mid, int k){
    int sum = 0;
    int stu=1;
    for(int i=0; i<n; i++){
        if(arr[i]>mid)
            return false;
        if(sum+arr[i]>mid){
            stu++;
            sum=arr[i];
            if(stu>k)
                return false;
        }else{
            sum+=arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int k){

    int lb = 0;
    int sum = 0;
    int ans=0;

    for(int i=0; i<n; i++)
        sum+=arr[i];
    
    int ub = sum;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(solve(arr, n, mid, k)){
            ans = mid;
            ub = mid-1;
        }else{
            lb = mid+1;
        }
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    cout<<findPages(arr, n, k);
}