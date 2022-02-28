#include <bits/stdc++.h>
using namespace std;

int countTriangles(int v,vector<vector<int>> &g , bool isDiagraph){

    int count=0;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            for(int k = 0; k<v; k++){
                if(g[i][j] && g[j][k] && g[k][i]){
                    count++;
                }
            }
        }
    }
    // return count;
    if(isDiagraph)
        return count/=3;
    else
        return count/=6;

}

int main(){

    int v, e;
    cin>>v>>e;

    vector<vector<int>> graph(v, vector<int>(v, 0));
    vector<vector<int>> diagraph(v, vector<int>(v, 0));


    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
        diagraph[x][y] = 1;
    }

    // for(int i=0; i<v; i++){
    //     for(int j=0; j<v; j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0; i<v; i++){
    //     for(int j=0; j<v; j++){
    //         cout<<diagraph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<countTriangles(v, graph, 0)<<endl;
    cout<<countTriangles(v, diagraph, 1);

}