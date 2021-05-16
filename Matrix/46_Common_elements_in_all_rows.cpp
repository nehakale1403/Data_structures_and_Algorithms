// The idea is to use maps. We initially insert all elements of the first row in an map. 
// For every other element in remaining rows, we check if it is present in the map. 
// If it is present in the map and is not duplicated in current row, 
// we increment count of the element in map by 1, else we ignore the element.
// If the currently traversed row is the last row, we print the element if it has appeared m-1 times before.

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int r, c;
    cin>>r>>c;

    int mat[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }

    unordered_map<int , int> mp;
    for(int j=0; j<c; j++)
        mp[mat[0][j]] = 1;

    for(int i=1; i<r; i++){
        for(int j=0; j<c; j++){
            if(mp[mat[i][j]] == i){
                mp[mat[i][j]] = i+1;

                if(i==r-1 && mp[mat[i][j]]==r)
                    cout<<mat[i][j]<<" ";
            }
        }
    }
}