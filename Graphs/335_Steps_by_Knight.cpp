#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int n, vector<int> &knightPos,vector<int> &targetPos){

    int x1 = knightPos[0];
    int y1 = knightPos[1];
    int x2 = targetPos[0];
    int y2 = targetPos[1];
    int a[n][n];

    if(x1 == x2 && y1 == y2) return 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x1-1, y1-1));
    while(!q.empty()){
        auto cur = q.front();
        int i = cur.first;
        int j = cur.second;
        q.pop();

        if((i+2)>=0 && (i+2)<n && (j+1)>=0 && (j+1)<n && a[i+2][j+1] == 0){
            a[i+2][j+1] = a[i][j] + 1;
            q.push(make_pair(i+2, j+1));
        }

        if((i+2)>=0 && (i+2)<n && (j-1)>=0 && (j-1)<n && a[i+2][j-1] == 0){
            a[i+2][j-1] = a[i][j] + 1;
            q.push(make_pair(i+2, j-1));
        }

        if((i+1)>=0 && (i+1)<n && (j+2)>=0 && (j+2)<n && a[i+1][j+2] == 0){
            a[i+1][j+2] = a[i][j] + 1;
            q.push(make_pair(i+1, j+2));
        }

        if((i-1)>=0 && (i-1)<n && (j+2)>=0 && (j+2)<n && a[i-1][j+2] == 0){
            a[i-1][j+2] = a[i][j] + 1;
            q.push(make_pair(i-1, j+2));
        }

        if((i-2)>=0 && (i-2)<n && (j+1)>=0 && (j+1)<n && a[i-2][j+1] == 0){
            a[i-2][j+1] = a[i][j] + 1;
            q.push(make_pair(i-2, j+1));
        }

        if((i-2)>=0 && (i-2)<n && (j-1)>=0 && (j-1)<n && a[i-2][j-1] == 0){
            a[i-2][j-1] = a[i][j] + 1;
            q.push(make_pair(i-2, j-1));
        }

        if((i-1)>=0 && (i-1)<n && (j-2)>=0 && (j-2)<n && a[i-1][j-2] == 0){
            a[i-1][j-2] = a[i][j] + 1;
            q.push(make_pair(i-1, j-2));
        }

        if((i+1)>=0 && (i+1)<n && (j-2)>=0 && (j-2)<n && a[i+1][j-2] == 0){
            a[i+1][j-2] = a[i][j] + 1;
            q.push(make_pair(i+1, j-2));
        }
    }    
    return  a[x2-1][y2-1];
}

int main(){

    int n;
    cin>>n;

    vector<int>knightPos(2);
	vector<int>targetPos(2);
    cin>>knightPos[0]>>knightPos[1];
    cin>>targetPos[0]>>targetPos[1];

    cout<<minStepToReachTarget(n, knightPos, targetPos);
}