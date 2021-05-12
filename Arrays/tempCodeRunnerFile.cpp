#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }

    int top=0, down=r-1, left=0, right=c-1;
    int dir=0;

    while(top<=down && left<=right){
        //left to right
        if(dir==0){
            for(int i=left; i<=right; i++)
                cout<<arr[top][i]<<" ";
            top++;
        }else if(dir==1){
            for(int i=top; i<=down; i++)
                cout<<arr[i][right]<<" ";
            right--;
        }else if(dir==2){
            for(int i=right; i>=left; i--)
                cout<<arr[down][i]<<" ";
            down--;
        }else if(dir==3){
            for(int i=down; i>=top; i--)
                cout<<arr[i][left]<<" ";
            left++;
        }
        dir = (dir+1)%4;
    }
}