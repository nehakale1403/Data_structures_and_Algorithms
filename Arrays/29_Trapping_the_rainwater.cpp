// The idea is to traverse every array element and find the highest bars on left and right sides.
// Take the smaller of two heights. 
// The difference between the smaller height and height of the current element is the 
// amount of water that can be stored in this array element.

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    
    int sum=0;
    for(int i=1; i<n-1; i++){
        
        int max_left=arr[i];
        int max_right=arr[i];
        for(int j=0; j<i; j++){
            max_left = max(max_left, arr[j]);
        }
        for(int k=i+1; k<n; k++){
            max_right = max(max_right, arr[k]);
        }
        sum = sum + (min(max_left, max_right) - arr[i]);
    }

    cout<<sum;
}