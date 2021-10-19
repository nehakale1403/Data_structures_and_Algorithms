#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int vis[][501], vector<vector<int>> arr, int n, int m){

    if(i<0 || j<0 || i>=n || j>=m) return;
    if(arr[i][j] == 0) return;
    if(!vis[i][j]){
        vis[i][j] = 1;
        dfs(i+1, j, vis, arr, n, m);
        dfs(i-1, j, vis, arr, n, m);
        dfs(i, j+1, vis, arr, n, m);
        dfs(i, j-1, vis, arr, n, m);
        dfs(i+1, j+1, vis, arr, n, m);
        dfs(i+1, j-1, vis, arr, n, m);
        dfs(i-1, j+1, vis, arr, n, m);
        dfs(i-1, j-1, vis, arr, n, m);
    }
}

int countIslands(vector<vector<int>> &arr, int n, int m){
    int vis[501][501];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            vis[i][j] = 0;
    
    int c=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && arr[i][j] == 1){
                dfs(i, j, vis, arr, n, m);
                c++;
            }
        }
    }
    return c;
}

int main(){
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m, '#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout<<countIslands(arr, n, m);
}