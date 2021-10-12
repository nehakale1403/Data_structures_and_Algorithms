#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void dfs(int i, int j, string s, vector<vector<int>> arr, int n, vector<vector<int>> &vis){

    if(i<0 || j<0 || i>=n || j>= n) return;
    if(arr[i][j] == 0 || vis[i][j] == 1) return;
    if(i == n-1 && j == n-1){
        v.push_back(s);
        return;
    }
    vis[i][j] = 1;

    dfs(i-1, j, s+'U', arr, n, vis);
    dfs(i+1, j, s+'D', arr, n, vis);
    dfs(i, j+1, s+'R', arr, n, vis);
    dfs(i, j-1, s+'L', arr, n, vis);

    vis[i][j] = 0;
}

vector<string> findpath(vector<vector<int>> arr, int n){

    v.clear();
    vector<vector<int>> vis(n, vector<int> (n));
    if(arr[0][0] == 0)  return v;
    if(arr[n-1][n-1] == 0) return v;
    string s = "";

    dfs(0, 0, s, arr, n, vis);
    sort(v.begin(), v.end());
    return v;
}



int main(){
    
    
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int> (n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    vector<string> ans = findpath(arr, n);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;
}