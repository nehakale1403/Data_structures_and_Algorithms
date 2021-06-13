#include<bits/stdc++.h>
using namespace std;

int main(){

    int m, n;
    cin>>m>>n;

    int arr1[m], arr2[n];
    for(int i=0; i<m i++)
        cin>>arr1[i];
    for(int i=0; i<n;i++)
        cin>>arr2[i];

    int k;
    cin>>k;

    int i=0, j=0;
    int idx=-1;
    while(i<m && j<n){
        if(arr1[i] <= arr2[j]){
            i++;
            idx++;
            if(idx == k)
            cout<<arr[i];
        }else if(arr1[i]>arr2[j]){
            j++;
            idx++;
            if(idx == k)
            cout<<arr[j];
        }
        

    }
}