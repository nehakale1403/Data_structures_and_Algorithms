#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+6;
vector<int> parent(n);
vector<int> sz(n);

void make_set(int v){
    parent[v]=v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    for(int i=0; i<n; i++){
        make_set(i);
    }

    int v, e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        int st, end, wt;
        cin>>st>>end>>wt;
        edges.push_back({wt, st, end});
    }

    sort(edges.begin(), edges.end());
    int cost=0;
    for(auto i:edges){
        int w = i[0];
        int s = i[1];
        int e = i[2];

        int x = find_set(s);
        int y = find_set(e);
        if(x == y)
            continue;
        else{
            cout<<s<<" "<<e<<endl;
            cost +=w;
            union_sets(s, e);

        }
    }
    cout<<cost<<endl;
}