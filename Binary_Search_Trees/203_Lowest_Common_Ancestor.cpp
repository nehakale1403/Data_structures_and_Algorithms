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

node* LCA(node* root, int n1, int n2){

    if(!root) return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    node *left_lca = LCA(root->left, n1, n2);
    node* right_lca = LCA(root->right, n1, n2);

    if(left_lca && right_lca)
        return root;

    if(left_lca)
        return left_lca;
    else
        return right_lca;
    
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    int n1, n2;
    cin>>n1>>n2;

    
    cout<<LCA(root, n1, n2)->data;

}

