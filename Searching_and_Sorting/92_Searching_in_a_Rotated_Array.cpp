// https://www.youtube.com/watch?v=oTfPJKGEHcc

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int key){
    int left = 0;
    int right=n-1;
    int mid;

    while(left<=right){
        mid = (left+right)/2;

        if(arr[mid] == key)
            return mid;
        //it means left half is constantly increasing
        else if(arr[mid] >= arr[left]){
            if(key<=arr[mid] && key>=arr[left])
                right = mid-1;
            else
                left = mid+1;
        }else{
            if(key<=arr[right] && key>=arr[mid])
                left = mid+1;
            else
                right = mid-1;
        }
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
    
    cout<<search(arr, n, key);
    
}