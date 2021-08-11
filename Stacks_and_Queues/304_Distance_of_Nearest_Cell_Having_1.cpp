#include<bits/stdc++.h>
using namespace std;
#define r 3
#define c 4

struct node{
    int x, y;
};

bool isvalid(int i, int j){
    return (i >= 0 && j >= 0 && i < r && j < c);
}

bool isdelim(node temp){
    return (temp.x == -1 && temp.y == -1);
}

vector<vector<int>> minDistance(vector<vector<int>> arr){

    queue<node> q;
    node temp;
    int dist=0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[i][j] == 1){
                temp.x = i;
                temp.y = j;
                q.push(temp);
                arr[i][j] = -1;
            }
        }
    }

    temp.x = -1;
    temp.y = -1;
    q.push(temp);

    while(!q.empty()){
        bool flag = false;

        while(!isdelim(q.front())){
            temp = q.front();
            if(isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 0){
                if (!flag) dist++, flag = true;
 
                arr[temp.x+1][temp.y] = dist;
 
                temp.x++;
                q.push(temp);
 
                temp.x--;
            }
            if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 0) {
                if (!flag) dist++, flag = true;
                arr[temp.x-1][temp.y] = dist;
                temp.x--;
                q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 0) {
                if (!flag) dist++, flag = true;
                arr[temp.x][temp.y+1] = dist;
                temp.y++;
                q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 0) {
                if (!flag) dist++, flag = true;
                arr[temp.x][temp.y-1] = dist;
                temp.y--;
                q.push(temp); // push this cell to Queue
            }
 
            q.pop();
        }
        q.pop();

        if (!q.empty()) {
            temp.x = -1;
            temp.y = -1;
            q.push(temp);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
    return arr;
}


int main(){

    vector<vector<int>> arr(r, vector<int>(c, -1));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int x;
            cin>>x;
            arr[i][j] = x;
        }
    }

    vector<vector<int>> ans = minDistance(arr);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}