#include<bits/stdc++.h>
using namespace std;


int main(){

    int v, e;
    cin>>v>>e;

    vector<int> g[v+1];
    vector<int> indeg(v+1, 0);

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        indeg[y]++;
    }

    vector<int> ans(v+1, 0);
    queue<int> q;
    for(int i=1; i<=v; i++){
        if(indeg[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
    }

    while(!q.empty()){
        int val =  q.front();
        q.pop();
        for(auto it:g[val]){
            indeg[it]--;
            if(indeg[it] == 0){
                ans[it] = ans[val]+1;
                q.push(it);
            }
        }
    }

    for(int i=1; i<=v; i++)
        cout<<ans[i]<<" ";

    return 0;
}