#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];

    int low, high;
    cin>>low>>high;

    int i=0, start=0, end=n-1;

    while(i<=end){
        if(arr[i]<low)
            swap(arr[i++], arr[start++]);
        else if(arr[i]>high)
            swap(arr[i], arr[end--]);
        else
            i++;
    }

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

}