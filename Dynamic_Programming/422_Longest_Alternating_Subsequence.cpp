#include <bits/stdc++.h>
using namespace std;

// int util(int arr[], int start, int end, bool flag){
//     int res = 0;

//     for(int i = start; i<=end; i++){
//         if(flag && arr[i-1] < arr[i])
//             res = max(res, 1+util(arr, i+1, end, !flag));
//         else if(!flag && arr[i-1] > arr[i])
//             res = max(res, 1+util(arr, i+1, end, !flag));
//         else{
//             res = max(res, util(arr, i+1, end, flag) );
//         }
//     }
//     return res;
// }

// int las(int arr[], int n){
    
//     if(n == 0) return 0;

//     return 1 + max(util(arr, 1, n-1, true), util(arr, 1, n-1, false));
// }


int las(int arr[], int n){
    int up = 1, down = 1;
	for(int i=1; i<n; i++) {
        if(arr[i]>arr[i-1]) up = down+1;
	    else if(arr[i]<arr[i-1]) down = up+1; 
	}
    return max(down, up);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<las(arr, n);
}