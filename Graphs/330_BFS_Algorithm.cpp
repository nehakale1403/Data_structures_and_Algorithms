#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]){

    vector<int> ans;
    queue<int> q;
    bool visited[v] = {0};

    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout<<"pushing "<<s<<endl;
        ans.push_back(s);
        for(int i=0; i<adj[s].size(); i++){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
                visited[adj[s][i]] = 1;
            }
        }
    }
    cout<<ans.size()<<endl;
    return ans;
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

    
    vector<int> ans = bfsOfGraph(v, g);

    for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
}