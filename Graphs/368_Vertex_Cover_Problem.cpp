#include <bits/stdc++.h>
using namespace std;

void vertexCover(vector<int> *adj, int v){

    bool vis[v] = {0};

    for(int i=0; i<v; i++){

        if(!vis[i]){

            for(auto j: adj[i]){

                if(!vis[j]){
                    vis[i] = true;
                    vis[j] = true;
                }
            }
        }
    }

    for(int i=0; i<v; i++){
        if(vis[i] == true)
            cout<<i<<" ";
    }


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

    vertexCover(adj, v);
}