#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int start=0, end=0;
    int curr_sum=0, min_length=n+1;
    while(end<n){
        while(curr_sum<=x && end<n)
            curr_sum+=arr[end++];
        
        while(curr_sum>x && start<n){
            if(end-start < min_length)
                min_length=end-start;
            
            curr_sum-=arr[start++];
        }

    }
    cout<<min_length;
}