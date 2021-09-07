#include<bits/stdc++.h>
using namespace std;

void displayBoard(int chess[][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printKnightsTour(int chess[][8], int r,int  c, int move){

    if(r<0 || c<0 || r >= 8 || c >= 8 || chess[r][c]>0){
        return;
    }else if(move == 8*8){
        chess[r][c] = move;
        displayBoard(chess);
        chess[r][c] = 0;
    }

    chess[r][c] = move;
    printKnightsTour(chess, r-2, c+1, move+1);
    printKnightsTour(chess, r-1, c+2, move+1);
    printKnightsTour(chess, r+1, c+2, move+1);
    printKnightsTour(chess, r+2, c+1, move+1);
    printKnightsTour(chess, r+2, c-1, move+1);
    printKnightsTour(chess, r+1, c-2, move+1);
    printKnightsTour(chess, r-1, c-2, move+1);
    printKnightsTour(chess, r-2, c-1, move+1);
    chess[r][c] = 0;
}

int main(){
    int n;
    cin>>n;
    int r, c;
    cin>>r>>c;

    int chess[8][8];
    printKnightsTour(chess, r, c, 1);
}