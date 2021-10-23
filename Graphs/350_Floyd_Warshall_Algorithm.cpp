#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    
    vector<vector<int>> g{{0, 5, inf, 10},{inf, 0, 3, inf}, {inf, inf, 0, 1}, {inf, inf, inf, 0}};


    int n = g.size();
    vector<vector<int>> dist = g;

    for(int k= 0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] == inf){
                cout<<"inf ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}