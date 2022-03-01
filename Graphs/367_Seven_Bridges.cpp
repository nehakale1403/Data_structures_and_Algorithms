#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> *adj, vector<int> &vis, int node){

    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(adj, vis, it);
        }
    }

}

bool anyEdgeOutside(vector<int> *adj, int v){

    int node = -1;
    vector<int> vis(v, 0);

    for(int i=0; i<v; i++){
        if(adj[i].size() >0){
            node = i;
            break;
        }
    }
    if(node == -1) return 0;


    DFS(adj, vis, node);

    for(int i=0; i<v; i++){
        if(vis[i] == 0 && adj[i].size() > 0)
            return 1;
    }

    return 0;
}

int findEuler(vector<int> *adj, int v){

    if(anyEdgeOutside(adj, v))
        return 0;

    int odd = 0;
    for(int i=0; i<v; i++){
        if(adj[i].size() & 1)
            odd++;
    }

    if(odd > 2)
        return 0; //not eulerian
    else if(odd == 0)
        return  2; //eulerian
    else if(odd == 1)
        return 1; //semi-eulerian
}

void pathPossible(vector<int> *adj, int v){

    int res = findEuler(adj, v);
    if(res == 0)
        cout<<"Euler path is not possible"<<endl;
    else if(res == 1)
        cout<<"Semi-Euler graph"<<endl;
    else
        cout<<"Euler graph"<<endl;

}


int main(){

    int v, e;
    cin>>v>>e;

    vector<int> adj[v];
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    pathPossible(adj, v);
}