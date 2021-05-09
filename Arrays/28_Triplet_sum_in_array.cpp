// O(n^2)

#include<bits/stdc++.h>
using namespace std;

bool findTriplet(int arr[], int n, int x){

    int j, k;
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++){
        j=i+1;
        k=n-1;
        while(j<k){
            if(arr[i]+arr[j]+arr[k]<x)
                j++;
            else if(arr[i]+arr[j]+arr[k] > x)
                k--;
            else if(arr[i]+arr[j]+arr[k] == x)
                return true;
        }
    }
    return false;

}

int main(){
    int n, x;
    cin>>n>>x;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    if(findTriplet(arr, n, x))
        cout<<"1";
    else    
        cout<<"0";
}