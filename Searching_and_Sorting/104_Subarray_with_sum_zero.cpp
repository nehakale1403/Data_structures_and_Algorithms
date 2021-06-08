#include<bits/stdc++.h>
using namespace std;

int countSubarray(int arr[], int n){

    
    int prefix_sum[n];
    int count=0;
    prefix_sum[0] = arr[0];

    for(int i=1; i<n; i++){     
        prefix_sum[i] = prefix_sum[i-1]+arr[i]; 
    }

    unordered_map<int, int> map;
    
    for(){
        int c = it.second;

        count+=(c*(c-1))/2;

        if(it.first == 0){
            count+=it.second
        }
    }
    return count;

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<countSubarray(arr, n);
}