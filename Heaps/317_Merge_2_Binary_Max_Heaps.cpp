#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int idx){

    if(idx >= n)
        return;
    int l = 2*idx +1;
    int r = 2*idx +2;
    int max;

    if(l<n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    
    if(r<n && arr[r] > arr[max]){
        max = r;
    }

    if(max != idx){
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}

void buildMaxHeap(int arr[], int n){
    
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m){
    for(int i=0; i<n; i++){
        merged[i] = a[i];
    }
    for(int i=0; i<m; i++){
        merged[n+i] = b[i];
    }

    buildMaxHeap(merged, n+m);
}

int main(){
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int merged[m + n];
    mergeHeaps(merged, a, b, n, m);
  
    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";
  
    return 0;
}

//this is the efficient method

// vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
//         // your code here
//         vector<int> ans;
//         int i=0,j=0;
//         while(i<n and j<m){
//             if(a[i]<b[j]){
//                 ans.push_back(b[j]);
//                 j++;
//             }
//             else{
//                 ans.push_back(a[i]);
//                 i++;
//             }
//         }
//         while(i<n){
//             ans.push_back(a[i]);
//                 i++;
//         }
//         while(j<m){
//             ans.push_back(b[j]);
//                 j++;
//         }
//         return ans;
// }