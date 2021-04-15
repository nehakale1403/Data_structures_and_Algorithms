#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right){

    int i, j, k, inv = 0;
    i = left;
    j = mid;
    k = left;

    while((i<=mid-1) && (j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            inv += mid-i;
        }
    }

    while(i<=mid-1){
        temp[k++] = arr[i++];
    }

    while(j<=right){
        temp[k++] = arr[j++];
    }

    for(int m = 0; m<=right; m++){
        arr[m] = temp[m];
    }
    return inv;
}

int mergesort(int arr[], int temp[], int left, int right){
    
    int inv = 0;
    if(left<right){
        int mid = (left+right)/2;

        inv += mergesort(arr, temp, left, mid);
        inv += mergesort(arr, temp, mid+1, right);
        inv += merge(arr, temp, left, mid+1, right);
    }
    return inv;
}
int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int temp[n];
    cout<<mergesort(arr, temp, 0, n-1);



    //brute force----O(n^2)
    // int count=0;
    // for(int i=0; i<n; i++){
    //     for(int j=n-1; j>i; j--){
    //         if(arr[i]>arr[j])
    //             count++;
    //     }
    // }
    // cout<<count;
}