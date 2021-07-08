#include<bits/stdc++.h>
using namespace std;

int start = 0;

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

void inOrder(node* root){

    if(root == NULL)
        return ;
    inOrder(root->left);
    cout<<root->data<<" "; 
    inOrder(root->right);

}


int sumtree(node* &root){
    if(!root) return 0;

    int old_val = root->data;

    root->data = sumtree(root->left)+ sumtree(root->right);

    return root->data+old_val;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    sumtree(root);
    
    inOrder(root);
}