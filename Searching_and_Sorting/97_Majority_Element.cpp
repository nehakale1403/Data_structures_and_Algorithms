#include<bits/stdc++.h>
using namespace std;

int findMajorityEle(int arr[], int n){

    unordered_map<int, int> map;

    for(int i=0; i<n; i++)
        map[arr[i]]++;
    
    for(auto it: map){
        if(it.second > n/2)
            return it.first;
    }
    return -1;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n ; i++)
        cin>>arr[i];
    
    cout<<findMajorityEle(arr, n);
}