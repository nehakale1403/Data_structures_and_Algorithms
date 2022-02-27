#include <bits/stdc++.h>
using namespace std;

bool canColor(vector<int> *adj, int v, int m, vector<int> &color){

    vector<bool> vis(v, 0);
    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        // cout<<"hello"<<endl;
        int node = q.front();
        q.pop();
        vis[node]= 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                if(color[node] == color[it]){
                    color[it]++;
                    if(color[it] > m) return false;
                }
            }
        }
    }
    return true;
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

    int m;
    cin>>m;

    vector<int> color(v, 1);

    cout<<canColor(adj, v, m, color);

}