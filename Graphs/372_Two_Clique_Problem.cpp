#include <bits/stdc++.h>
using namespace std;

bool areTwoCliques(vector<vector<int>> &g, int v){

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g[i][j] = !g[i][j];
        }
    }

    vector<int> color(v, 1);
    vector<bool> vis(v);

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = 1;
        for(int i=node, j=0; j<v; j++){
            if(g[i][j] == 1 && !vis[j]){
                if(color[i] == color[j])
                    color[j]++;
                if(color[j] > 2) return false;
                q.push(j);
            }
        }
    }
    return true;
}  

int main(){
    int v,e;
    cin>>v>>e;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int flag = 0;
    for(int i=0; i<v;i++){
        for(int j=0; j<v; j++){
            if(graph[i][j] == 0 && i!=j){
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }

    if(flag == 1)
        areTwoCliques(graph, v);
    else
        cout<<"0";
}