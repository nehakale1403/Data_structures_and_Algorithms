//for 1 element log n time is req....for n elements nlogn time

#include<bits/stdc++.h>
using namespace std;

void deleteele(int arr[], int n){
    
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    int x,i,j;
    int del = arr[0];
    x = arr[n-1];

    arr[0] = arr[n-1];
    i = 0;
    j = 2*i + 1;

    while(j<n-1){
        if(arr[j+1] > arr[j]){
            j = j+1;
        }
        if(arr[i] < arr[j]){
            swap(arr[i], arr[j]);
            i=j;
            j = 2*j +1;
        }else{
            break;
        }
    }   
    arr[n-1] = del;
}
void insert(int arr[], int n){
    int temp;
    int i=n;
    temp = arr[n];
    while(i>0 && temp > arr[(i-1)/2]){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=1; i<n; i++){
        insert(arr, i);
    }

    for(int i=0; i<n; i++)
        cout<<arr[i];

    cout<<endl;
    int count=n;
    for(int i=0; i<n; i++){
        deleteele(arr, count);
        count--;
    }
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}