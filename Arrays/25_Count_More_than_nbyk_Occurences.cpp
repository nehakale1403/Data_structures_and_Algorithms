#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    map<int, int> mp;
        int p = n/k;
        int count=0;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            if(it.second > p){
                
                count++;
            }
        }
        
    cout<<count;
}