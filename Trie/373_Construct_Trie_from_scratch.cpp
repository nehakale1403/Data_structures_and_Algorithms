#include<bits/stdc++.h>
using namespace std;



struct trieNode{
    char data;
    int wc;
    trieNode *child[26];
    
    
};

    trieNode nodepool[100000];  //Pool of 100K trieNode
    trieNode *root;    //Root of Trie
    int poolcount;  //Always points to next free trieNode

void init(){
        poolcount = 0;
        root = &nodepool[poolcount++];
        root->data = NULL;

        for(register int i=0; i<26; i++)
            root->child[i] = NULL;
    }

    trieNode *getNode(char c){
        trieNode *newnode = &nodepool[poolcount++];
        newnode->data = c;

        for(register int i=0; i<26; i++)
            newnode->child[i] = NULL;
        newnode->wc = 0;
    }

    void insert(char *s){
        trieNode *curr = root;
        int index;
        for(int i=0; s[i]!= '\0'; i++){
            index = s[i] - 'a';
            if(curr->child[index] == NULL){
                curr->child[index] = getNode(s[i]);
            }
            curr->child[index]->wc +=1;
            curr = curr->child[index];
        }
    }

    bool search(char *s){
        trieNode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; i++){
            index = s[i] - 'a';
            if(curr->child[index] == NULL || curr->child[index]->wc == 0)
                return false;
            curr = curr->child[index];
        }
        return true;
    }

    bool trieDelete(char *s){
        if(search(s)){
            trieNode *curr = root;
            int index;
            for(int i=0; s[i]!='\0'; i++){
                index = s[i] - 'a';
                curr->child[index]->wc -= 1;
                curr = curr->child[index];
            }
        }
    }

    int countPrefix(char *s){
        trieNode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; i++){
            index = s[i] - 'a';
            if(curr->child[index] == NULL || curr->child[index]->wc == 0)
                return 0;
            curr = curr->child[index];
        }
        return curr->wc;
    }



int main()
{
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    trieDelete(a);
    trieDelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}
