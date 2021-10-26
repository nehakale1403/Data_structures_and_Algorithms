#include <bits/stdc++.h>
using namespace std;

vector<int> order;

void dfs(int src, vector<int> &vis, vector<int> g[]){
    vis[src] = 1;
    for(auto x: g[src]){
        if(!vis[x]){
            dfs(x, vis, g);
        }
    }
    order.push_back(src);
}

void rdfs(int src, vector<int> &vis1, vector<int> rev[]){
    vis1[src] = 1;
    for(auto x: rev[src]){
        if(!vis1[x]){
            dfs(x, vis1, rev);
        }
    }
}

int solution(vector<int> adj[],int v){

    vector<int> rev[v];

    for(int y=0; y<v; y++){
        for(auto x: adj[y]){
            rev[x].push_back(y);
        }
    }

    vector<int> vis(v, 0);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, adj);
        }
    }

    vector<int> vis1(v, 0);
    int col = 0;
    for(int i=v-1; i>=0; i--){
        if(!vis[order[i]]){
            rdfs(order[i], vis1, rev);
            col++;
        }
    }
    return col;
}

int main(){

    int v, e;
    cin>>v>>e;

    vector<int> adj[v];

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    cout<<solution(adj,v);
}