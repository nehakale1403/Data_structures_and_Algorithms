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
void leftTree(node* root,vector<int> &ans){
    if(!root) return;
    if(root->left){
        ans.push_back(root->data);
        leftTree(root->left, ans);
    }else if(root->right){
        ans.push_back(root->data);
        leftTree(root->right, ans);
    }
}

void leaf(node* root, vector<int> &ans){
    if(!root) return;

    leaf(root->left, ans);
    if(!root->left && !root->right)
        ans.push_back(root->data);
    leaf(root->right, ans);
}

void rightTree(node* root, vector<int> &ans){
    if(!root) return;
    if(root->right){
        rightTree(root->right, ans);
        ans.push_back(root->data);    
    }else if(root->left){
        rightTree(root->left, ans);
        ans.push_back(root->data);      
    }
}

void boundaryTraversal(node* root){

    if(root == NULL)
        return;
    
    vector<int> ans;
    ans.push_back(root->data);
    leftTree(root->left, ans);
    leaf(root, ans);
    rightTree(root->right, ans);
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
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
    

    boundaryTraversal(root);
    
}