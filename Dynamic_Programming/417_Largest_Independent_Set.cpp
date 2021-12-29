#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
};

int LISS(node *root){
    if(root == NULL) return 0;

    int excl = LISS(root->left) + LISS(root->right);

    int incl = 1;
    if(root->left){
        incl += LISS(root->left->left) + LISS(root->left->right);
    }
    if(root->right)
        incl += LISS(root->right->left) + LISS(root->right->right);
    
    return max(incl, excl);
}

node* newNode( int data ){

    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    cout<<LISS(root);
}