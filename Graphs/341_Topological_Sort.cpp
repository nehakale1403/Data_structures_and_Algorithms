#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int v, e;
    cin>>v>>e;

    int cnt = 0;
    vector<int> adj[v];
    vector<int> indeg(v, 0);
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        cnt++;
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
}