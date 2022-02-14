#include<bits/stdc++.h>
using namespace std;


class trieNode{
    char data;
    int we;
    trieNode *arr[26];

    public:
        trieNode* newNode(char c){
            trieNode *t = new trieNode();
            t->data = c;
            t->we = 0;
            for(int i=0; i<26; i++){
                t->arr[i] = NULL;
            }
            return t;
        }

        void insertWord(string s, trieNode *root){
            trieNode *curr = root;
            for(int i=0; i<s.length(); i++){
                // cout<<"inserting "<<s[i]<<endl;
                int index = s[i] - 'a';
                if(curr->arr[index] == NULL)
                    curr->arr[index] = newNode(s[i]);    
                curr = curr->arr[index];
            }
            curr->we ++;
        }

        void deleteWord(string s, trieNode *root){
            trieNode *curr = root;
            for(int i=0; i<s.length(); i++){
                int index = s[i] - 'a';
                if(curr->arr[index] == NULL)
                    return;
                curr = curr->arr[index];
            }
            curr->we--;
        }

        bool search(string s, trieNode *root){
            trieNode *curr = root;
            for(int i=0; i<s.length(); i++){
                // cout<<"searching for "<<s[i]<<endl;
                int index = s[i] - 'a';
                if(curr->arr[index] == NULL)
                    return false; 
                curr = curr->arr[index];
                if((i == s.length()-1) && curr->we == 0)
                    return false;
            }
            return true;
        }

        bool wordBreak(string key, trieNode *root){

            if(key.length() == 0) return true;

            for(int i=1; i<=key.length(); i++){
                if(search(key.substr(0, i), root) && wordBreak(key.substr(i, key.length()-i), root)){
                    return true;
                }
            }
            return false;
        }

        void travNode(trieNode *root){
            cout<<root->data<<endl;

            for(int i=0;i<26;i++){
                if(root->arr[i] != NULL){
                    travNode(root->arr[i]);
                }
            }
        }


};


int main(){

    trieNode obj;
    trieNode *root = obj.newNode('/');
    
    vector<string> dict = { "i", "like", "sam", "sung", "samsung", "mobile",
                        "ice","cream", "icecream", "man", "go", "mango"};
    

    for(int i=0; i<dict.size(); i++){
        obj.insertWord(dict[i], root);
    }

    // cout<<obj.search("sam", root);

    string key = "ilikesam";

    cout<<obj.wordBreak(key, root);


}
