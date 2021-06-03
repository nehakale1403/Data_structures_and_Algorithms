#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int low, int high, int key, int n){

    if(low<=high){
        int mid = low+ (high-low)/2;
        if((mid == 0 || arr[mid-1]<key) && arr[mid] == key)
            return mid;
        else if(key>arr[mid])
            return first(arr, mid+1, high, key, n);
        else
            return first(arr, low, mid-1, key, n);
    }
    return -1;
}
int last(int arr[], int low, int high, int key, int n){
    if(low<=high){
        int mid = low+ (high-low)/2;
        if((mid==n-1 || key < arr[mid+1]) && arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            return last(arr, low, mid-1, key, n);
        else    
            return last(arr, mid+1, high, key, n);
    }
    return -1;
}

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int key;
    cin>>key;

    cout<<first(arr, 0, n-1, key, n)<<" "<<last(arr, 0, n-1, key, n);

}