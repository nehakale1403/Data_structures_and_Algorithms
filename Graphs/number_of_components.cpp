#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[], vector<int>&vis, int v, int node)
{

    if(vis[node] == 0)
    {
        vis[node] = 1;

        for(auto it: g[node])
        {
            DFS(g,vis,v,it);
        }
    }
    return;
}

int noOfComp(vector<int> g[], int v)
{

    int comp = 0;
    vector<int> vis(v,0);

    for(int i=0;i<v;i++)
    {
        if(vis[i] == 0)
        {
            comp++;
            DFS(g,vis,v,i);
        }
    }

    return comp;
}
int main(){
    int v, e;
    cin>>v>>e;

    //adjacency list
    vector<int> g[v];
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    cout<<noOfComp(g,v);

}