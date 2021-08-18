#include<bits/stdc++.h>
using namespace std;

int findPlatformNo(int arr[], int dep[], int n){

    sort(arr, arr+n);
    sort(dep, dep+n);

    int i=1, j=0;
    int max=0;
    int platform_req=1;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            platform_req++;
            i++;
        }else if(arr[i]>=dep[j]){
            platform_req--;
            j++;
        }

        if(platform_req > max)
            max = platform_req;
    }
    return max;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<findPlatformNo(arr, dep, n);
}