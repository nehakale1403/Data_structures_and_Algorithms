#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){

    vector<pair<int, int>> adj[n];
    for(auto it:flights){
        adj[it[0]].push_back({it[1], it[2]});
    } 

    set<vector<int>> s;
    s.insert({0, src, k});
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(s.begin());
        int cost = x[0], node = x[1], stops = x[2];
        cout<<cost<<" "<<node<<" "<<stops<<endl;
        if(node == dst) return cost;
        if(stops >= 0){
            for(auto &it:adj[node]){
                s.insert({cost + it.second, it.first, stops-1});
            }
        }
    }
    return -1;
   
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> flights(n, vector<int>(n));
    for(int i=0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        flights[i][0] = x;
        flights[i][1] = y;
        flights[i][2] = z;
    }

    int src, dst, k;
    cin>>src>>dst>>k;
    cout<<findCheapestPrice(n, flights, src, dst, k);
}