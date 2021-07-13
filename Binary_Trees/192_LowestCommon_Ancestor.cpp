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


node* lca(node* root, int n1, int n2){
    
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;
 
    // Look for keys in left and right subtrees
    node *left_lca  = lca(root->left, n1, n2);
    node *right_lca = lca(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
    
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
    cout<<lca(root, n1, n2)->data;
    
}