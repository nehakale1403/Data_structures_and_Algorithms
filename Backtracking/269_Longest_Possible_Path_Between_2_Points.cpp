#include<bits/stdc++.h>
using namespace std;

#define m 10
#define n 10

int vis[m][n];

bool isValid(int x, int y, int mat[m][n]){
    if(x>=0 && y>=0 && x<m && y<n && mat[x][y] == 1 && !vis[x][y])
        return true;
    return false;
}

void findLongestPath(int mat[m][n], int i, int j, int x, int y, int &max_dist, int dist){
    if(i == x && j == y){
        max_dist = max(max_dist, dist);
        return;
    }

    vis[i][j] = 1;

    if(isValid(i+1, j, mat)) findLongestPath(mat, i+1, j, x, y, max_dist, dist+1);
    if(isValid(i-1, j, mat)) findLongestPath(mat, i-1, j, x, y, max_dist, dist+1);
    if(isValid(i, j+1, mat)) findLongestPath(mat, i, j+1, x, y, max_dist, dist+1);
    if(isValid(i, j-1, mat)) findLongestPath(mat, i, j-1, x, y, max_dist, dist+1);

    vis[i][j] = 0;
}

int main(){
    
    int mat[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    int max_dist = 0;
    findLongestPath(mat, 0, 0, 5, 7, max_dist, 0);

    cout<<max_dist;
}