#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void topView(node *root){

    if(root == NULL)    
        return;
    
    map<int, int> m;
    queue<pair<node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        node *t = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!m[h])
            m[h] = t->data;
        if(t->left)
            q.push({t->left, h-1});
        if(t->right)
            q.push({t->right, h+1});
    }
    for(auto x:m)
        cout<<x.second<<" ";
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    topView(root);
    
}