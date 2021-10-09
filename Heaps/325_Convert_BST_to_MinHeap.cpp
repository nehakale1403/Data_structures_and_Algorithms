#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

struct node* newnode(int data){

    struct node *newn = new node;
    newn->data = data;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

void preorderTraversal(node*);

void inorderTraversal(node* root, vector<int> &arr){

    if(root == NULL)
        return;
    
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void BSTtoMinHeap(node* root, vector<int> arr, int *i){
    if(root == NULL)
        return;
    
    root->data = arr[++*i];
    BSTtoMinHeap(root->left, arr, i);
    BSTtoMinHeap(root->right, arr, i);
}

void convertToMinHeap(node* root){

    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTtoMinHeap(root, arr, &i);
}

void preorderTraversal(node * root){
    if(!root)
        return;
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    struct node *root = newnode(4);
    root->left = newnode(2);
    root->right = newnode(6);
    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(7);
 
    convertToMinHeap(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
}