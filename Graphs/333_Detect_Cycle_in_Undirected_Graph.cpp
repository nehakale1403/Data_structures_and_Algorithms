#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<int> adj[], vector<bool> &vis){

    vis[src] = true;
    for(auto x: adj[src]){
        if(!vis[x]){
            if(dfs(x, src, adj, vis))
                return true;
        }else if(x != parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(int v, vector<int> adj[]){

    vector<bool> vis(v, false);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            bool f = dfs(i, -1, adj, vis);
            if(f) return true;
        }
    }
    return false;

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

    
    cout<<isCyclic(v, g);

}