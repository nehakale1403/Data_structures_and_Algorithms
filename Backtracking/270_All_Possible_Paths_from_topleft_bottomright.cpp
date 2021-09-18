#include<bits/stdc++.h>
using namespace std;

void printPaths(int sr,int sc, int dr,int dc, string path){

    if(sr>dr || sc>dc){
        return;
    }
    if(sr == dr && sc == dc){
        cout<<path<<endl;
        return;
    }

    printPaths(sr, sc+1, dr, dr, path + "h");
    printPaths(sr+1, sc, dr, dc, path + "v");
    
}


int main(){
    int n, m;
    cin>>n>>m;
    printPaths(1,1,n,m, "");
}