#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> &vis, vector<int> g[], int &counter){
    vis[src] = 1;
    counter++;
    for(auto x: g[src]){
        if(!vis[x]){
            dfs(x, vis, g, counter);
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;
     
    vector<int> g[v];
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> solution;
    vector<int> vis(v, 0);

    for(int i=0; i<v; i++){
        if(!vis[i]){
            int counter = 0;
            dfs(i, vis, g, counter);
            solution.push_back(counter);
        }
    }

    int val = (v*(v-1))/2;
    for(int i=0; i<solution.size(); i++){
        int x = (solution[i]*(solution[i]-1))/2;
        val = val-x;
    }
    cout<<val;
}