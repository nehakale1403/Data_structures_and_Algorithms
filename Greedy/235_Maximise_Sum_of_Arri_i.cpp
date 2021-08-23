#include<bits/stdc++.h>
using namespace std;

int maximise(int a[], int n){

    sort(a, a+n);
    int mod = 1e9 + 7;
    long long sum=0;
    
    for(int i=0; i<n; i++){
        sum = (sum + ((long long)a[i]*i) % mod) % mod;
    }
        
    return (int) sum;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maximise(arr, n);
}