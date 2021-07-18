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

node* construct(node* &root, int ele){

    if(!root) 
        return root = new node(ele);
    
    if(root->data > ele)
        root->left = construct(root->left, ele);
    else
        root->right = construct(root->right, ele);
    
    return root;
}

node* constructBST(int pre[], int n){

    node* root = NULL;

    for(int i=0;i<n; i++)
        construct(root, pre[i]);
    
    return root;
    
}

int main(){

    int n;
    cin>>n;

    int pre[n];
    for(int i=0; i<n; i++)
        cin>>pre[i];

    node* root = constructBST(pre, n);

    inorder(root);
}

