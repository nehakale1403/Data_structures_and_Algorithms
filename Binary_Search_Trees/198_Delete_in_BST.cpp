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

node* inorderSuccessor(node* root){
    node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

node* deleteNode(node* root, int k){
    
    if(!root){
        return NULL;
    }

    if(k< root->data){
        root->left = deleteNode(root->left, k);

    }else if(k> root->data){
        root->right = deleteNode(root->right, k);

    }else{

        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            node * temp = root->left;
            free(root);
            return temp;
        }

        node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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
    deleteNode(root, k);
    inorder(root);
}

