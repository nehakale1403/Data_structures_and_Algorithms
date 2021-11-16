#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int key){

    int l=0;
    int r = n-1;
    int mid;

    while(l<=r){
        mid = l + (r-l)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] >= arr[l]){
            if(key <= arr[mid] && key >= arr[l]){
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }else{
            if(key > arr[mid]){
                if(key<=arr[r] && key>=arr[mid])
                l = mid+1;
            else
                r = mid-1;
            }
        }
    }

    return -1;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int key;
    cin>>key;

    cout<<search(arr, n, key);
}