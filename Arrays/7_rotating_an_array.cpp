#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++){
        if(i==n-1){
            cin>>a[0];
        }
        cin>>a[i+1];
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

}

//method 2 is to take the array...store the last element and do a[i] = a[i-1]....for n-1 to 1