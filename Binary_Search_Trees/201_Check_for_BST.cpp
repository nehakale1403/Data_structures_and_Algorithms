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

bool checkBST(node* root){

    if(!root) return true;

    if(root->left != NULL && root->left->data > root->data){
        return false;
    }
    if(root->right != NULL && root->right->data < root->data){
        return false;
    }
    
    if(!checkBST(root->left) || !checkBST(root->right)){
        return false;
    }
    return true;
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    if(checkBST(root)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

