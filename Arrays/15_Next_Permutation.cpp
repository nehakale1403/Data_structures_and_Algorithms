#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int i = n-2;
    while(arr[i]>=arr[i+1])
        i--;

    if(i>=0){
        int j= n-1;
        while(arr[j]<=arr[i]) j--;

        swap(arr[i], arr[j]);
    }

    reverse(arr, i+1, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i];
}