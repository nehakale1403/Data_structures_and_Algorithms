#include <bits/stdc++.h>
using namespace std;

int f=0;

void dfs(int src, int parent, int col, vector<vector<int>> &g, vector<int> &vis){
    
    vis[src] = col;
    for(auto x: g[src]){
        if(vis[x] == -1){
            dfs(x, src, 3-col, g, vis);
        }else if(x!=parent && col == vis[x]){
            f = 1;
            break;
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>> g(v+1);
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    f = 0;
    vector<int> vis(v+1, -1);
    dfs(1, 0, 1, g, vis);
    if(f)
        cout<<"Not Bipartite";
    else
        cout<<"Bipartite";
}