#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr, arr+n);
    int median=0;
    if(n%2==0){
        median = (arr[(n-1)/2]+arr[(n/2)])/2;
    }else{
        median = arr[n/2];
    }
    cout<<median;
    return 0;
}