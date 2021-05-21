#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int i=n-1;
    while(arr[i]>=arr[i+1]){
        i--;
    }

    if(i>=0){
        int j=n-1;
        while(arr[i]<=arr[j])
            j--;
        swap(arr[i], arr[j]);
    }

    reverse(arr, i+1, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i];
}