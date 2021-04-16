#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, sum;
    cin>>n>>sum;
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    unordered_map<int, int> m;
    int count = 0;

    for(int i=0; i<n; i++){
        
        int diff = sum - arr[i];
        if(m[diff] == 0){
            m[arr[i]]++;
        }else{
            count += m[diff];
            m[arr[i]]++;
        }
    }
    cout<<count;
}