#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int main(){
    int v, e;
    cin>>v>>e;

    vector<int> dist(v+1, inf);
    vector<pair<int, int>> graph[v+1];
    for(int i=0; i<e; i++){
        int p,q,wt;
        cin>>p>>q>>wt;
        graph[p].push_back({q, wt});
        graph[q].push_back({p, wt});
    }

    int source;
    cin>>source;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(dist[i] < inf){
            cout<<dist[i]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }
}