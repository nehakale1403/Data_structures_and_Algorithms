#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int div = n/k;
    sort(arr, arr+n);
    int count=1;
    int final_count=0;
    int i=0;
    while(i<n){
        while(arr[i] == arr[i+1]){
            count++;
            i++;
        }
        if(count>div){
            final_count++;
        }
        count=1;
        i++;
    }
    cout<<final_count;
}