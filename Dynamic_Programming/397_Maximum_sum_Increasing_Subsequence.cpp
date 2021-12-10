#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int maxSumIS(int arr[],int next, int n){

    if(n == 0)
        return 0;

    if(mp.find({next, n}) != mp.end())
        return mp[{next, n}];
    
    if(next <= arr[n-1]){
        return mp[{next, n}] =  maxSumIS(arr, next, n-1);
    }else{
        return mp[{next, n}] = max(maxSumIS(arr, next, n-1), arr[n-1] + maxSumIS(arr, arr[n-1], n-1));
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxSumIS(arr,INT_MAX, n)<<endl;

}
