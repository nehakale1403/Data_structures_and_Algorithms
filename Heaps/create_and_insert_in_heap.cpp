//for 1 element log n time is req....for n elements nlogn time

#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int n){
    int temp;
    int i=n;
    temp = arr[n];
    while(i>0 && temp > arr[(i-1)/2]){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=1; i<n; i++){
        insert(arr, i);
    }

    for(int i=0; i<n; i++)
        cout<<arr[i];
}