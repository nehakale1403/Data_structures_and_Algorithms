#include<bits/stdc++.h>
using namespace std;

int findTriplets(int arr[], int n, int x){

    if(n == 1 || n == 2)
        return -1;
    int i, j;
    int count=0;
    sort(arr, arr+n);

    for(i=0; i<n-2; i++){
        int left=i+1, right=n-1;
        while(left<right){
            if(arr[i]+arr[left]+arr[right] >= x){
                right--;
            }else{
                // For current i and left, there
                // can be total right-j third elements.(all elements are smaller to the left of var right)
                count+=right-left;
                left++;
            }
        }
    }
    return count;
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int x;
    cin>>x;
    cout<<findTriplets(arr, n, x);
}