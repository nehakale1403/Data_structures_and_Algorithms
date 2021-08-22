#include<bits/stdc++.h>
using namespace std;

int sumArray(int arr[], int n){

    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int maximize(int arr[], int n, int k){

    sort(arr, arr+n);
    int i=0;

    for(int i=0; i<n; i++){
        if(k && arr[i]< 0){
            arr[i] *= -1;
            k--;
            continue;
        }
        break;
    }

    if(i == n)
        i--;
    
    if(k == 0 || k%2 == 0){
        return sumArray(arr, n);
    }

    if(i!=0 && abs(arr[i]) >= abs(arr[i-1])){
        i--;
    }
    arr[i] *= -1;

    return sumArray(arr, n);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    cout<<maximize(arr, n, k);
}