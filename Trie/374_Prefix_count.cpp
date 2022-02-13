#include<bits/stdc++.h>
using namespace std;


class trieNode{
    
    char data;
    int we;
    int pc; //prefix count
    trieNode *arr[26];

    public:
        trieNode* newNode(char c){
            trieNode *t = new trieNode();
            t->data = c;
            t->we = 0;
            if(c != '/') t->pc = 1;
            else t->pc = 0;
            for(int i=0; i<26; i++){
                t->arr[i] = NULL;
            }
            return t;
        }

        void insertWord(string s, trieNode *root){
            trieNode *curr = root;
            for(int i=0; i<s.length(); i++){

                int index = s[i] - 'a';
                if(curr->arr[index] == NULL){
                    curr->arr[index] = newNode(s[i]);  
                    curr = curr->arr[index];
                    // curr->pc++;
                }else{     
                    curr = curr->arr[index];
                    curr->pc++;
                }
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

        vector<string> shortestUniquePrefix(vector<string> v, trieNode *root){

            vector<string> res;

            for(int i=0; i<v.size(); i++){
                cout<<v[i]<<endl;
                string word = v[i];
                trieNode *curr = root;
                string prefix = "";
                for(int j = 0; j<word.length(); j++){
                    int index = word[j] - 'a';
                    curr = curr->arr[index];
                    if(curr->pc == 1){
                        prefix = prefix + word[j];
                        res.push_back(prefix);
                        break;
                    }
                    prefix = prefix + word[j];

                }
            }
            return res;
        }


};


int main(){

    trieNode obj;
    trieNode *root = obj.newNode('/');

    obj.insertWord("zebra", root);
    obj.insertWord("dog", root);
    obj.insertWord("duck", root);
    obj.insertWord("dove", root);
    // obj.insertWord("doll", root);

    // cout<<obj.search("zebra", root)<<endl;
    // cout<<obj.search("dog", root)<<endl;
    // cout<<obj.search("duck", root)<<endl;
    // cout<<obj.search("dove", root)<<endl;
    // cout<<obj.search("doll", root)<<endl;

    vector<string> v = {"zebra", "dog", "duck", "dove"};
    vector<string> res = obj.shortestUniquePrefix(v, root);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
}