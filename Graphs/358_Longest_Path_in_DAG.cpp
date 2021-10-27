#include <bits/stdc++.h>
using namespace std;

vector<int> order;

void topo(int src, vector<int> &vis, vector<vector<pair<int, int>>> g){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first])
            topo(x.first, vis, g);
    }
    order.push_back(src);
    
}

int main(){
    int v, e;
    cin>>v>>e;

    int src;
    cin>>src;

    vector<vector<pair<int, int>>> g(v);
    for(int i=0; i<e; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y, wt});
    }

    vector<int> vis(v, 0);
    for(int i=0; i<v; i++){
        if(!vis[i])
            topo(i, vis, g);
    }

    vector<int> dist(v);
    for(int i=0; i<v; i++)
        dist[i] = INT_MIN;
    
    dist[src] = 0;
    for(int i=v-1; i>=0; i--){
        if(dist[order[i]] != INT_MIN){
            for(auto x: g[order[i]]){
                int vv = dist[x.first];
                int ww = x.second;
                int uu = dist[order[i]];
                if(uu + ww > vv){
                    dist[x.first] = uu + ww;
                }
            }
        }
    }

    for(int i=0; i<v; i++){
        if(i!=src && dist[i] != INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }
}