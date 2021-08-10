// https://www.youtube.com/watch?v=CxrnOTUlNJE
#include<bits/stdc++.h>
#define R 3
#define C 5
using namespace std;

bool isvalid(int i, int j){
    return (i >= 0 && j >= 0 && i < R && j < C);
}

struct ele {
    int x, y;
};

bool isdelim(ele temp){
    return (temp.x == -1 && temp.y == -1);
}

bool checkall(int arr[][C])
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (arr[i][j] == 1)
             return true;
    return false;
}

int rotOranges(int arr[][C]){

    queue<ele> q;
    ele temp;
    int ans=0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == 2){
                temp.x = i;
                temp.y = j;
                q.push(temp);
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
            if(isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1){
                if (!flag) ans++, flag = true;
 
                arr[temp.x+1][temp.y] = 2;
 
                temp.x++;
                q.push(temp);
 
                temp.x--;
            }
            if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
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
    return (checkall(arr))? -1: ans;
}

int main()
{
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rotn";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}