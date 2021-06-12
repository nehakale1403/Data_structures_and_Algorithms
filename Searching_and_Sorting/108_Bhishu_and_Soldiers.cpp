//https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int arr[], int q, int power[]){

    sort(arr, arr+n);

    for(int i=0; i<q; i++){

        int count=0;
        int total_pow = 0;
        for(int j=0; j<n; j++){
            if(arr[j]<=power[i]){
                count++;
                total_pow+=arr[j];
            }else{
                break;
            }
        }
        cout<<count<<" "<<total_pow<<endl;
    }
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int q;
    cin>>q;

    int power[q];
    for(int i=0; i<q; i++)
        cin>>power[i];
    
    solve(n, arr, q, power);
}