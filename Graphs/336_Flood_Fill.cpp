#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &arr, int newColor, int n, int m, int oldColor){
    if(i<0 || j<0 || i>=n || j>=m) return;
    if(vis[i][j] || arr[i][j]!= oldColor) return;

    vis[i][j] = 1;
    arr[i][j] = newColor;
    dfs(i+1, j, vis, arr, newColor, n, m, oldColor);
    dfs(i-1, j, vis, arr, newColor, n, m, oldColor);
    dfs(i, j+1, vis, arr, newColor, n, m, oldColor);
    dfs(i, j-1, vis, arr, newColor, n, m, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &arr, int sr, int sc, int newColor){

    int x = arr.size();
    int y = arr[0].size();
    vector<vector<int>> vis(x, vector<int> (y, 0));
    int oldColor = arr[sr][sc];
    dfs(sr, sc, vis, arr, newColor, x, y, oldColor);

    return arr;
}

int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int sr,sc;
    int newColor;
    cin>>sr>>sc>>newColor;

    floodFill(arr, sr, sc, newColor);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

