#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
        

    int output[n];
    int product=1;
    for(int i=0; i<n; i++){
        product*=arr[i];
        output[i] = product;
    }

    product=1;
    for(int i=n-1; i>0; i--){
        output[i] = output[i-1]*product;
        product *= arr[i];
    }
    output[0] = product;

    for(int i=0; i<n; i++)
        cout<<output[i]<<" ";
    
}