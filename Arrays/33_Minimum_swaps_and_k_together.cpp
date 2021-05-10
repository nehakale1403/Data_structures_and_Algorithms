#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]>=k)
            count++;
    }

    int bad=0;
    for(int i=0; i<count; i++){
        if(arr[i]>k)
            bad++;
    }
    int result=bad;
    for(int i=0, j=count; j<n; i++, j++){
        if(arr[i]>k)
            bad--;
        if(arr[j]>k)
            bad++;

        result = min(result, bad);
    }
    cout<<result;
}