#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr, arr+n);
    int min_diff = INT_MAX;
    for(int i=0; i<n-m+1; i++){
        int left = arr[i];
        int right = arr[i+m-1];
        cout<<left<<" "<<right<<endl;
        min_diff = min(min_diff, right-left);
    }
    cout<<min_diff;
}