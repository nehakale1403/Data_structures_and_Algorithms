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

void diagonalTraversal(node* root){

    if(root == NULL)
        return;
    
    queue<node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        while(temp){
            if(temp->left)
                q.push(temp->left);
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    diagonalTraversal(root);
    
}