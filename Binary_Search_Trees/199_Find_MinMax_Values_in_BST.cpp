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

int minElement(node* root){

    if(!root) return NULL;

    if(root->left == NULL){
        return root->data;
    }
    return minElement(root->left);
  
}

int maxElement(node* root){

    if(!root) return NULL;

    if(root->right == NULL){
        return root->data;
    }
    return maxElement(root->right);

    
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    cout<<minElement(root)<<endl;
    cout<<maxElement(root);
}

