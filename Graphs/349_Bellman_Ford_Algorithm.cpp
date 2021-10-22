#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int v, e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        int s, e, wt;
        cin>>s>>e>>wt;
        edges.push_back({s, e, wt});
    }

    int src;
    cin>>src;

    vector<int> dist(v, inf);

    dist[src] = 0;
    for(int iter = 0; iter< v-1; iter++){
        for(auto e: edges){
            int uu = e[0];
            int vv = e[1];
            int ww = e[2];
            dist[vv] = min(dist[vv], ww + dist[uu]);
            cout<<dist[vv]<<" ";
        }
        cout<<endl;
    }

    for(auto it: dist)
        cout<<it<<" ";
}