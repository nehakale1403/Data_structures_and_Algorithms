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
                cout<<"inserting "<<s[i]<<endl;
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
                cout<<"searching for "<<s[i]<<endl;
                int index = s[i] - 'a';
                if(curr->arr[index] == NULL)
                    return false; 
                curr = curr->arr[index];
                if((i == s.length()-1) && curr->we == 0)
                    return false;
            }
            return true;
        }


};


int main(){

    trieNode obj;
    trieNode *root = obj.newNode('/');
    obj.insertWord("hello", root);
    obj.insertWord("hell", root);
    obj.insertWord("neha", root);
    obj.insertWord("avaneesh", root);

    cout<<obj.search("hello", root)<<endl;
    cout<<obj.search("neha", root)<<endl;
    cout<<obj.search("avan", root)<<endl;

    obj.deleteWord("hello", root);

    cout<<obj.search("hell", root)<<endl;
    cout<<obj.search("hello", root)<<endl;


}