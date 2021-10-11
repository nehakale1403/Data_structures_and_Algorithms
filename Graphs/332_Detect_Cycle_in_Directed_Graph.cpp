#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<int> &visited, int s, vector<int> &rest){

    visited[s]=true;
    rest[s]=true;
       
    for(int u:adj[s]){
        if(visited[u]==false){
           if(dfs(adj,visited,u,rest))
                return true;
        }else if(rest[u]==true)
            return true;
    }
    rest[s]=false;
    return false;
}

bool isCyclic(int v, vector<int> adj[]){

    vector<int> visited(v, 0);
    vector<int> rest(v, 0);
    bool flag = false;
    for(int i=0; i<v; i++){
        if(visited[i] == 0){
            if(dfs(adj, visited, i, rest))
                return true;
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
    }

    
    cout<<isCyclic(v, g);

}