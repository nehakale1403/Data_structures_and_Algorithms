#include <bits/stdc++.h>
using namespace std;

bool solve(vector<pair<int, int>> *adj, vector<bool> &vis, int k, int src){
    
    if (k <= 0)
        return true;
 
    for (auto it:adj[src])
    {
        // int v = i.first;
        // int w = i.second;
 
        if (vis[it.first] == true)
            continue;

        if (it.second >= k)
            return true;

        vis[it.first] = true;
 
        if (solve(adj, vis, k-it.second, it.first))
            return true;
 
        // Backtrack
        vis[it.first] = false;
    }

    return false;


    //   if(k <= 0) return true;
    

    // for(auto it: adj[src]){
    //     if(path[it.first]==1)
    //         continue;

    //     if(it.second >= k) return true;

    //     path[it.first] = 1;
        
    //     if(solve(adj, path, k-it.second, it.first))
    //         return true;
    
    //     path[src] = 0;
    // }
    // return false;
}

bool findPathGreaterThanK(vector<pair<int, int>> *adj, int k, int v, int src){

    vector<bool> vis(v, 0);
    vis[src] = 1;
    return solve(adj, vis, k, src);
}

int main(){

    int v, e;
    cin>>v>>e;

    vector<pair<int, int>> adj[v];

    for(int i=0; i<e; i++){
        int x, y, cost;
        cin>>x>>y>>cost;
        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost});
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;

    int src;
    cout<<"Enter src: ";
    cin>>src;
    cout<<findPathGreaterThanK(adj, k, v, src);
}


// 9 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
