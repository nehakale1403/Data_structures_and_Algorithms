#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        int word_count;
        char data;
        TrieNode *arr[2];

        TrieNode(char ch){
            word_count = 0;
            data = ch;
            for(int i=0; i<2; i++)
                arr[i] = NULL;
        }

        void insertWord(string s, TrieNode &root){

            TrieNode *p = &root;
            for(int i=0; i<s.length(); i++){
                char c = s[i];
                if(p->arr[s[i]-'0'] == NULL){
                    p->arr[s[i]-'0'] = new TrieNode(s[i]);
                }
                p = p->arr[s[i]-'0'];
            }
            p->word_count++;
        }

        bool searchWord(string s, TrieNode &root){

            TrieNode *p = &root;
            for(int i=0; i<s.length(); i++){
                char ch = s[i];
                if(p->arr[s[i]-'0'] != NULL){
                    p = p->arr[s[i]-'0'];
                }else{
                    return false;
                }
            }
            if(p->word_count != 0)
                return true;
            return false;
        }

        void printUniqueRows(TrieNode &root, string s){

            s += root.data;
            if(root.word_count > 0){
                cout<<s<<" ";
            }
            for(int i=0; i<2; i++){
                if(root.arr[i] != NULL){
                    printUniqueRows(*root.arr[i], s);
                }
            }
        }

};


int main(){

    TrieNode root('$');

    int r=3, c=4;

    vector<vector<int>> v = {{1, 1, 0, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}};

    
    for(int i=0; i<r; i++){
        string a = "";
        for(int j=0; j<c; j++){
            a += (char)(v[i][j] + 48);
        }
        root.insertWord(a, root);
    }

    root.printUniqueRows(root, "");
}