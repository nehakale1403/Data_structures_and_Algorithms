#include<bits/stdc++.h>
using namespace std;

int counter(vector<vector<int>> mat, int n, int mid){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if(mat[i][j]<=mid){
                count = count+ j+1;
                break;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    int key;
    cin>>key;
    int l=arr[0][0];
    int h = arr[n-1][n-1];

    while(l<h){
        int mid = l+ (h-l)/2;
        int count = counter(arr, n, mid);
        if(count>=key)
            h=mid;
        else
            l=mid+1;

    }
    cout<<l;

    
}