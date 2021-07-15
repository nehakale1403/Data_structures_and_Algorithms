#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left;
    int data;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node* root){

    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* insertNode(node* root, int k){
    
    if(!root){
        return new node(k);
    }
    if(k == root->data){
        return root;
    }
    if(k > root->data){
        root->right = insertNode(root->right, k);
    }else{
        root->left = insertNode(root->left, k);
    }

    return root;
    
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    int k;
    cin>>k;
    insertNode(root, k);
    inorder(root);
}

