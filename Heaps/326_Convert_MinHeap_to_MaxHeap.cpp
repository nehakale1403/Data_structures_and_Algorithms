#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int i, int n){

    int l = 2*i +1;
    int r = 2*i +2;
    int largest = i;

    if(l<n && arr[l] > arr[i])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }

}

void convertToMaxHeap(int arr[], int n){

    for(int i= (n-2)/2; i >= 0; --i){
        maxHeapify(arr, i, n);
    }
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    printArray(arr, n);
    convertToMaxHeap(arr, n);
    printArray(arr, n);
}