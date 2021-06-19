#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){

    int start2 = mid+1;

    if(arr[mid]<=arr[start2]){
        return;
    }

    while(start<=mid && start2<=end){

        if(arr[start] <= arr[start2]){
            start++;
        }else{
            int value = arr[start2];
            int idx = start2;

            while(idx!=start){
                arr[idx] = arr[idx-1];
                idx--;
            }
            arr[start] = value;

            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(int arr[], int l, int r){

    if(l<r){
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)  
        cout<<arr[i];
}