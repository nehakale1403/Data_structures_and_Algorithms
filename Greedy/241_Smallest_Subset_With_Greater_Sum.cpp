#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int smallestSubset(int arr[], int n){

    sort(arr, arr+n, comp);
    
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int count=0;
    int temp=0;
    int i=0;
    while(temp <= sum/2){
        temp += arr[i++];
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<smallestSubset(arr, n)<<" ";
}