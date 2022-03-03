#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        int word_count;
        char c;
        TrieNode *arr[26];

        TrieNode(char ch){
            word_count = 0;
            c = ch;
            for(int i=0; i<26; i++)
                arr[i] = NULL;
        }

        void insertWord(string s, TrieNode &root, int idx){

            TrieNode *p = &root;
            for(int i=0; i<s.length(); i++){

                char c = s[i];
                if(p->arr[s[i] - 'a'] == NULL){
                    p->arr[s[i] - 'a'] = new TrieNode(s[i]);
                }
                p = p->arr[s[i] - 'a'];
            }
            p->word_count++;
        }

        bool searchWord(string s, TrieNode &root){

            TrieNode *p = &root;
            for(int i=0; i<s.length(); i++){
                char ch = s[i];
                if(p->arr[s[i] - 'a'] != NULL){
                    p = p->arr[s[i] - 'a'];
                }else{
                    return false;
                }
            }
            if(p->word_count != 0)
                return true;
            return false;
        }

        void printNames(TrieNode &root, string s){

            int flag = 0;

            s += root.c;
            if(root.word_count > 0){
                cout<<s<<" ";
            }
            for(int i=0; i<26; i++){
                if(root.arr[i] != NULL){
                    printNames(*root.arr[i], s);
                    flag =1;
                }
            } 
        }

        void phoneDir(TrieNode &root, string s){

            TrieNode *p = &root;
            for(int i=0; i<s.length(); i++){
                char ch = s[i];
                if(p->arr[s[i] - 'a'] != NULL){
                    string str = s.substr(0, i);
                    printNames(*p->arr[s[i]-'a'], str);
                    cout<<endl;
                    p = p->arr[s[i]-'a'];
                }else{
                    cout<<0<<endl;
                }
            }
        }
};


int main(){

    TrieNode root('/');

    vector<string> v = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    
    for(int i=0; i<v.size(); i++){
        root.insertWord(v[i], root, i);
    }

    string word = "geeips";

    root.phoneDir(root, word);
}