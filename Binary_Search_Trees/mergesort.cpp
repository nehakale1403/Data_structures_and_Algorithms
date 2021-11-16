#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int h){

    int n1 = mid - l+1;
    int n2 = h - mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0; i<n1; i++){
        arr1[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        arr2[i] = arr[mid+i+1];
    }

    int i=0, j=0, k = l;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k++] = arr1[i++];
    }

    while(j<n2){
        arr[k++] = arr2[j++];
    }
}

void mergesort(int arr[], int l, int h){
    if(l>=h)
        return;
    int mid = l + (h-l)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, h);
    merge(arr, l, mid, h);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    mergesort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i];
}