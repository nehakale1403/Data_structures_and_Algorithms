#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res[v];
    bool available[v];
    res[0] = 0;
    for(int i=1; i<v; i++) res[i] = -1;
    for(int i=0; i<v; i++) available[i] = true;

    int cn = 0;
    for(int i=1; i<v; i++){
        for(auto x: g[i]){
            if(res[x] != -1){
                available[res[x]] = false;
            }
        }

        int cr=0;
        for(cr=0; cr<v; cr++){
            if(available[cr]){
                break;
            }
        }

        res[i] = cr;
        cn = max(cn, cr+1);

        for(auto x: g[i]){
            if(res[x] != -1){
                available[res[x]] = true;
            }
        }
    }

    cout<<cn<<endl;
    for(int i=0; i<v; i++)
        cout<<res[i];
}