#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin>>r>>c;

    bool arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }
    int result=-1, flag=0;
    //as the row are sorted, we check columnwise. once we find 1, 
    // we will break the loop and return the row number
    for(int col=0; col<c; col++){
        for(int row=0; row<r; row++){
            if(arr[row][col] == 1){
                result=row;
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    cout<<result;
}