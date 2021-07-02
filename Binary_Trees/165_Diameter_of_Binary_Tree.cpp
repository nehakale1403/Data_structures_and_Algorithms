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

int height(node* root){
    if(root == NULL)
        return 0;
    
    return 1+ max(height(root->left), height(root->right));
}

int diameter(node* root){

    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight + rheight + 1,  max(ldiameter, rdiameter));

      
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    cout<<diameter(root);
    
}