#include<bits/stdc++.h>
using namespace std;

int maxStocks(int arr[], int n, int k){

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        v.push_back(make_pair(arr[0], i+1));
    }

    sort(v.begin(), v.end());

    int ans=0;
    for(int i=0; i<n; i++){
        ans += min(v[i].second, k/v[i].first);
        k -= v[i].first * min(v[i].second, k/v[i].first);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    cout<<maxStocks(arr, n, k);
}