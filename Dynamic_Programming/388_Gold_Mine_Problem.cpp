#include<bits/stdc++.h>
using namespace std;

int getMaxGold(int gold[][4], int m, int n){

    for(int col=n-2; col>=0; col--){
        for(int row = 0; row<m; row++){
            int right = gold[row][col+1];
            int right_up = (row == 0)? 0 :gold[row-1][col+1];
            int right_down = (row == m-1)? 0 :gold[row+1][col+1];

            gold[row][col]= gold[row][col] + max({right, right_up, right_down});
        }
    }

    int res= gold[0][0];
    for(int i=1; i<m; i++)
        res= max(res, gold[i][0]);
    return res;

}

int main(){
    int gold[4][4] = {  {1, 3, 1, 5},
                        {2, 2, 4, 1},
                        {5, 0, 2, 3},
                        {0, 6, 1, 2}
                    };
    
    cout<<getMaxGold(gold, 4, 4);
}



// int goldtable[m][n];
//     memset(goldtable, 0, sizeof(goldtable));

//     for(int col = n-1; col >=0; col--){
        
//     }