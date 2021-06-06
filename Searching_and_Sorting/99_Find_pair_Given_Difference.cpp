#include<bits/stdc++.h>
using namespace std;

int findPair(int arr[], int n, int key){

    sort(arr, arr+n);
    int i=0, j=0;
    while(i<n && j<n){
        if(i!=j && arr[j]-arr[i] == key)
            return 1;
        else if(arr[j]-arr[i] < key)
            j++;
        else    
            i++;
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
    cout<<findPair(arr, n, key);
}