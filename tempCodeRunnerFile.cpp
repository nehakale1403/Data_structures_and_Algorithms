#include<bits/stdc++.h>
using namespace std;

void processArray(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i] % 10 == 6 && arr[i] < 55){
            arr[i] = -5;
        }else if(arr[i] %10 == 6){
            arr[i] = -2;
        }else if(arr[i] < 55){
            arr[i] = -4;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    processArray(arr, n);
    vector<int> array;

    for(int i=0; i<n; i++) cout<<arr[i];
}