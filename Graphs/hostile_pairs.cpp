#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int v){

    bool vis[v] = {0};
    stack<int> st;
    vector<int> ans;

    st.push(0);
    vis[0] = 1;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        ans.push_back(node);

        for(auto it: graph[node]){
            if(!vis[it]){
                st.push(it);
                vis[it] = 1;
            }
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

void bfs(vector<int> graph[], int v){

    bool vis[v] = {0};
    queue<int> q;
    vector<int> res;

    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int node = q.front();
        res.push_back(node);
        q.pop();
        for(auto it: graph[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<int> graph[v];

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    bfs(graph, v);
    cout<<endl;
    dfs(graph, v);
}
