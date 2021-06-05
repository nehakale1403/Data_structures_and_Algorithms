#include<bits/stdc++.h>
using namespace std;

int searchIdx(int arr[], int n, int k, int x){

    int i=0;
    while(i<n){

        if(arr[i] == x)
            return i;
        
        i = i + max(1, abs(arr[i]-x)/k);
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k, x;
    cin>>k>>x;
    cout<<searchIdx(arr, n, k, x);
}