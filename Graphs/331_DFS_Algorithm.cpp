#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
void solve(int src, vector<int> &vis, vector<int> adj[]){

    vis[src] = 1;
    ans.push_back(src);
    for(auto x: adj[src]){
        if(!vis[x]){
            solve(x, vis, adj);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]){


    vector<int> vis(v, 0);
    solve(0, vis, adj);

    return ans;
}

int main(){
    int v, e;
    cin>>v>>e;

    //adjacency list
    vector<int> g[v];
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    
    vector<int> ans = dfsOfGraph(v, g);

    for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
}