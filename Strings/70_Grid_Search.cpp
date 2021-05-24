#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<char>>& board, int i, int j, string& word, int idx){
        if(idx == word.length() - 1) return true;
        board[i][j] -= 65;
        if(i > 0 && board[i-1][j] == word[idx+1] && search(board, i-1, j, word, idx+1)) return true;
        if(j > 0 && board[i][j-1] == word[idx+1] && search(board, i, j-1, word, idx+1)) return true;
        if(i < board.size()-1 && board[i+1][j] == word[idx+1] && search(board, i+1, j, word, idx+1)) return true;
        if(j < board[0].size()-1 && board[i][j+1] == word[idx+1] && search(board, i, j+1, word, idx+1)) return true;
        board[i][j] += 65;
        return false;
}

bool exist(vector<vector<char>>& board, string word){
    int r = board.size();
    if(r == 0) return false;
    int c = board[0].size();
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            if(board[i][j] == word[0] && search(board, i, j, word, 0)) return true;
    return false;
}

int main(){
    
    int r, c;
    cout<<"input the r and c"<<endl;
    cin>>r>>c;

    vector<vector<char>> board(r, vector<char> (c));

    for(int i=0; i<r; i++){
        
        for(int j=0; j<c; j++){
            char c;
            cin>>c;
            board[i][j] = c;
        }
    }
    
    string word;
    cout<<"Enter the word "<<endl;
    cin>>word;

    if(exist(board, word)){
        cout<<"Yes";
    }
    else
        cout<<"No";
}