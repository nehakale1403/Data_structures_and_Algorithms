#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[], vector<int> visited, int curr){
    if(visited[curr] == 1)
        return true;
    
    visited[curr] = 1;
    bool flag = false;
    for(int i=0; i<adj[curr].size(); i++){
        flag = isCyclicUtil(adj, visited, adj[curr][i]);
        if(flag == true)
            return true;
    }

    return false;
}

bool isCyclic(int v, vector<int> adj[]){

    vector<int> visited(v, 0);
    bool flag = false;
    for(int i=0; i<v; i++){
        visited[i] = 1;
        for(int j=0; j<adj[i].size(); j++){
            flag = isCyclicUtil(adj, visited, adj[i][j]);
            if(flag == true)
                return true;
        }
        visited[i] = 0;
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