#include<bits/stdc++.h>
using namespace std;

int maximise(int arr[], int n){

    vector<int> v;
    
    sort(arr, arr+n);
    
    for(int i=0; i< n/2; i++){
        v.push_back(arr[i]);
        v.push_back(arr[n-1-i]);
    }

    if(n%2 != 0)
        v.push_back(arr[n/2]);

    int ans=0;

    for(int i=0; i< n-1; i++){
        ans = ans + abs(v[i] - v[i+1]);
    }
    
    ans += abs(v[n-1] - v[0]);

    return ans;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maximise(arr, n);
}