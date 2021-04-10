// https://www.youtube.com/watch?v=gmu0RA5_zxs&ab_channel=NickWhite

#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    k = k % n;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i];
    }

}