#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

bool detectNegativeCycle(vector<vector<int>> g, int V){

    vector<int> path(V, inf);
    path[0] = 0;
    int i, j;
    for(i=0; i<V-1; i++){
        for(j=0; j<g.size(); j++){
            int u = g[j][0];
            int v = g[j][1];
            int wt = g[j][2];

            if(path[u] == inf){
                continue;
            }

            if(path[v] > path[u] + wt){
                path[v] = path[u]+wt;
            }
        }
    }

    for(j=0; j<g.size(); j++){
        int u = g[j][0];
        int v = g[j][1];
        int wt = g[j][2];

        if(path[u] == inf){
            continue;
        }

        if(path[v] > path[u] + wt){
            cout<<"Yes"<<endl;
            return true;
        }
    }
    cout<<"No"<<endl;
    return false;

}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>> g(v, vector<int> (v));
    for(int i=0; i<e; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        g[i][0] = x;
        g[i][1] = y;
        g[i][2] = wt;

    }
    
    detectNegativeCycle(g, v);
}