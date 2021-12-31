#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n){

    int mpist = 0; //max profit if sold today
    int mtn = arr[0]; //min till now
    int dpleft[n] = {0}; //dp max profit if sold upto today
    for(int i=1; i<n; i++){
        mtn = min(mtn, arr[i]);
        mpist = arr[i] - mtn;

        if(mpist > dpleft[i-1]){
            dpleft[i] = mpist;
        }else{
            dpleft[i] = dpleft[i-1];
        }
    }

    int mpibt = 0; //max profit if bought today
    int maxat = arr[n-1]; //max after today
    int dpright[n] = {0}; // max profit on the right

    for(int i=n-2; i>=0; i--){
        maxat = max(maxat, arr[i]);

        mpibt = maxat - arr[i];
        if(mpibt > dpright[i+1])
            dpright[i] = mpibt;
        else
            dpright[i] = dpright[i+1];
    }

    for(int i=0; i<n; i++) cout<<dpleft[i]<<" ";
    cout<<endl;
    for(int i=0; i<n; i++) cout<<dpright[i]<<" ";
    cout<<endl;
    int op = 0;
    for(int i=0; i<n; i++){
        op = max(op, dpleft[i] + dpright[i]);
    }
    return op;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxProfit(arr, n);
}