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

int findLevel(node *root, int k, int level)
{
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree
    // or right subtree, return true;
    if (root->data == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}

node* LCA(node* root, int n1,int n2){

     if (root == NULL)
       return root;
    if (root->data == n1 || root->data == n2)
       return root;
 
    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
           return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}


int findDistance(node* root, int n1, int n2){
    
    // We first find the LCA of two nodes. Then we find the distance from LCA to two nodes. 
    node* lca = LCA(root, n1, n2);
 
    int d1 = findLevel(lca, n1, 0);
    int d2 = findLevel(lca, n2, 0);
 
    return d1 + d2;
    
    
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int n1, n2;
    cin>>n1>>n2;
    cout<<findDistance(root, n1, n2);
    
}