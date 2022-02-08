#include <bits/stdc++.h>
using namespace std;

void findTwoNumbers(int n, int arr[]){
    int xxory = 0;

    for(int i=0; i<(2*n +2); i++){
        xxory = xxory ^ arr[i];
    }

    int rsbm = xxory & -xxory;

    int x = 0, y = 0;
    for(int i=0; i<(2*n +2); i++){
        if((arr[i] & rsbm) == 0){
            x = x ^ arr[i];
        }else{
            y = y ^ arr[i];
        }
    }

    cout<<x<<" "<<y;
}

int main(){
    int n;
    cin>>n;

    int arr[2*n + 2];
    for(int i=0; i< (2*n +2); i++) cin>>arr[i];

    findTwoNumbers(n, arr);
}