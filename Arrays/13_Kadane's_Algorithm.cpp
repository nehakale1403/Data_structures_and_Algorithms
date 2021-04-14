#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int max_current = arr[0];
    int max_global = arr[0];

    for(int i=1; i<n; i++){
        max_current = max(arr[i], max_current+arr[i]);

        if(max_global<max_current)
            max_global = max_current;
    }
    cout<<max_global;
}