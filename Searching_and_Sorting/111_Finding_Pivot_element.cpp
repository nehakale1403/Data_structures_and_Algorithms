#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int n, int low, int high){

    int mid = low + (high-low)/2;

    if(n==1)
        return arr[0];
    if(arr[mid]>=arr[mid+1])
        return arr[mid];
    else if(arr[mid-1]>arr[mid])
        return arr[mid-1];
    else if(arr[mid]<arr[high]){
        findPivot(arr, n, low, mid-1);
    }else if(arr[mid]>arr[high]){
        findPivot(arr, n, mid, high);
    }
    return -1;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<findPivot(arr, n, 0, n-1);
}