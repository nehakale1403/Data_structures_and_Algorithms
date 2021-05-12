#include<bits/stdc++.h>
using namespace std;

int main(){

    int c, r;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
        
    int smallest=arr[0][0];
    int largest =arr[r-1][c-1];

    if(key<smallest || key> largest)
        cout<<"False";
    int top = 0, left=0, right=c-1, down=r-1;
    int flag=0;
    while(top<r){

        if(arr[top][left]<key && arr[top][right]<key){
            top++;
        }else if(arr[top][left]<key && arr[top][right]>key){
            for(int i=0; i<c; i++){
                if(arr[top][i]==key){
                    flag=1;
                    break;
                }                  
            }
        }else if(arr[top][left]>key && arr[top][right]>key){
            flag=0;
            break;
        }
        if(flag==1)
            break;
        
    }    
    if(flag==1){
        cout<<"True";
    }else{
        cout<<"False";
    }  

}