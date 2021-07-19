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

void inorder(node* root, vector<int> &temp){

    if(!root) return;

    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}

void printInorder(node* root){

    if(!root) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

node* copyEle(node* &root, vector<int> temp){

    static int i=0;
    if(!root) return NULL;

    copyEle(root->left, temp);
    root->data = temp[i];
    i++;
    copyEle(root->right, temp);
}

node* binToBST(node* root){

    if(!root) return NULL;
    vector<int> temp;

    
    inorder(root, temp);

    sort(temp.begin(), temp.end());

    return copyEle(root, temp);
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    binToBST(root);

    printInorder(root);
}

