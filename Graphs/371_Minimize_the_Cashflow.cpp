#include <bits/stdc++.h>
using namespace std;

void minimizeCashflow(int v, vector<vector<int>> graph){

    vector<int> cost(v);
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(graph[i][j] !=0){
                cost[i] -= graph[i][j];
                cost[j] += graph[i][j];
            }
        }
    }

    int minele = INT_MAX;
    int maxele = INT_MIN;
    int minidx, maxidx;

    while(minele!=0 && maxele!=0){

        minele = INT_MAX;
        maxele = INT_MIN;

        for(int i=0; i<v; i++){
            if(minele > cost[i]){
                minidx = i;
                minele = cost[i];
            }
            if(maxele < cost[i]){
                maxidx = i;
                maxele = cost[i];
            }
        }
        int transfer = min(abs(minele), maxele);
        if(transfer == 0) break;
        cost[minidx] += transfer;
        cost[maxidx] -= transfer;

        cout<<minidx<<" pays "<<transfer<<" to "<<maxidx<<endl;
    }

}

int main(){
    
    int v, e;
    cin>>v>>e;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for(int i=0; i<e; i++){
        int x, y, cost;
        cin>>x>>y>>cost;
        graph[x][y] = cost;
    }

    minimizeCashflow(v, graph);
}