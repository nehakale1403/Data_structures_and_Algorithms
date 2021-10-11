#include<bits/stdc++.h>
using namespace std;


vector<int> dfsOfGraph(int v, vector<int> adj[]){

    vector<int> ans;
    vector<int> vis(v, 0);
    
    stack<int> st;

    st.push(0);
    vis[0] = 1;

    while(!st.empty()){
        int ele = st.top();
        ans.push_back(ele);
        st.pop();
        for(auto it: adj[ele]){
            if(!vis[it]){
                vis[it] = 1;
                st.push(it);
            }
        }
    }

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

    
    vector<int> ans = dfsOfGraph(v, g);

    for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
}