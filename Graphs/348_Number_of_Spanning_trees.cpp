#include<bits/stdc++.h>
using namespace std;

// #define N 3
// int v;

// void subMatrix(int mat[N][N], int temp[N][N], int p, int q, int n) {
//    int i = 0, j = 0;
//    // filling the sub matrix
//    for (int row = 0; row < n; row++) {
//       for (int col = 0; col < n; col++) {
//          // skipping if the current row or column is not equal to the current
//          // element row and column
//          if (row != p && col != q) {
//             temp[i][j++] = mat[row][col];
//             if (j == n - 1) {
//                j = 0;
//                i++;
//             }
//          }
//       }
//    }
// }

// int determinantOfMatrix(int matrix[][N], int n) {
//    int determinant = 0;
//    if (n == 1) {
//       return matrix[0][0];
//    }
//    if (n == 2) {
//       return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
//    }
//    int temp[N][N], sign = 1;
//    for (int i = 0; i < n; i++) {
//       subMatrix(matrix, temp, 0, i, n);
//       determinant += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
//       sign = -sign;
//    }
//    return determinant;
// }

int countST(vector<int> g[], int v, int e){

    int mat[v][v];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i == j){
                mat[i][j] = g[i].size();
            }else{
                if(std::find(g[i].begin(), g[i].end(), j) != g[i].end()){
                    mat[i][j] = -1;
                }else{
                    mat[i][j] = 0;
                }
            }
        }
    }
    //return cofactor of any element in the matrix
    // return determinantOfMatrix(mat, v-1);    
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<int> g[e];

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout<<countST(g, v, e);
}