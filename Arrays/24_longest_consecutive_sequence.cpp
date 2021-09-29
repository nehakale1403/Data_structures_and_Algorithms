#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(s.find(arr[i]-1) == s.end()){
        
            int j = arr[i]+1;
            while(s.find(j) != s.end()){
                j++;
            }
        
            ans = max(ans, j-arr[i]);
        }
    }

    cout<<ans;
    // sort(arr, arr+n);
    // int max_count = 0;
    // int count=1;
    // for(int i=0; i<n; i++){
    //     if(arr[i]+1 ==arr[i+1]){
    //         count++;
    //     }else if(arr[i] == arr[i+1]){
    //         continue;
    //     }else{
    //         count=1;
    //     }
            
    //     max_count = max(count, max_count);
    // }

    // cout<<max_count;
}