#include <bits/stdc++.h>
using namespace std;

int minEdgesToReverse(int v, int e, vector<pair<int, int>> *adj, int src, int dst){

    //{node, cost}
    set<pair<int, int>> s;
    s.insert({0, 0});
    vector<int> dist(v, 1e7);
    dist[src] = 0;

    while(!s.empty()){
        // cout<<"hello"<<endl;
        pair<int, int> node = *(s.begin());
        s.erase(node);
        for(auto it: adj[node.first]){
            if(dist[node.first] + it.second < dist[it.first]){
                s.erase({it.first, dist[it.first]});
                dist[it.first] = dist[node.first] + it.second;
                s.insert({it.first, dist[it.first]});
            }
        }
    }
    return dist[dst];
}

int main(){
    
    int v, e;
    cin>>v>>e;

    vector<pair<int, int>> adj[v];

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }

    int src, dst;
    cin>>src>>dst;

    cout<<minEdgesToReverse(v, e, adj, src, dst);
}