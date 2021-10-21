#include<bits/stdc++.h>
using namespace std;

int v, e;

const int INF = 1e9;
const int N = 1e5 + 3;
vector<int> dist(N), parent(N);

vector<vector<int>> g[N];
vector<bool> vis(N);

int cost = 0;


void primsMST(int src){

    for(int i=1; i<e; i++){
        dist[i] = INF;
    }

    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0, src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int st = x[1];
        int end = parent[x[1]];
        int wt = x[0];
        cout<<st<<" "<<end<<" "<<wt<<endl;
        cost += wt;
        for(auto it: g[x[1]]){
            if(vis[it[0]])
                continue;
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main(){
    
    cin>>v>>e;

    

    for(int i=0; i<e; i++){
        int s, e, wt;
        cin>>s>>e>>wt;
        g[s].push_back({e, wt});
        g[e].push_back({s, wt});
    }

    primsMST(0);
    cout<<cost;
}