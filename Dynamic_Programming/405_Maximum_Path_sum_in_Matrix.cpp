#include<bits/stdc++.h>
using namespace std;

int maximumPath(int n, vector<vector<int>> arr){

    for(int row = n-2; row >=0; row--){
        for(int col = 0; col <n; col++){
            arr[row][col] += max({ arr[row+1][col], col == 0 ? 0 : arr[row+1][col-1], col == n-1 ?0 : arr[row+1][col+1]});
        }
    }
    int ans = INT_MIN;
    for(int col = 0; col<n; col++){
        if(arr[0][col] > ans) ans = arr[0][col];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0; i<n*n; i++)
        cin>>arr[i/n][i%n];
    
    cout<<maximumPath(n, arr);
}