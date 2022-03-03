#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        int word_count;
        char c;
        TrieNode *arr[26];
        vector<int> indexList;

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
            p->indexList.push_back(idx);
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

        void printAnagrams(TrieNode &root, vector<string> &v){

            TrieNode *p = &root;
            
            for(int i=0; i<26; i++){
                if(p->arr[i] != NULL){
                    printAnagrams(*p->arr[i], v);
                }
            }
            if(p->indexList.size() > 0){
                for(int j=0; j< p->indexList.size(); j++){
                    cout<<v[p->indexList[j]]<<" ";
                }
                cout<<endl;
            }
        }

};


int main(){

    TrieNode root('/');

    vector<string> v = {"no", "on", "is"};
    
    for(int i=0; i<v.size(); i++){
        string s = v[i];
        sort(s.begin(), s.end());
        root.insertWord(s, root, i);
    }

    root.printAnagrams(root, v);
}