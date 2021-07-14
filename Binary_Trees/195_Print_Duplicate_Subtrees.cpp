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


string inorder(node *root, unordered_map<string, int> &m){

    if(!root) return "";

    string s="(";
    s = s+inorder(root->left, m);
    s = s+ to_string(root->data);
    s = s+ inorder(root->right, m);
    s += ")";

    if(m[s] == 1){
        cout<<root->data<<" ";
    }
    m[s]++;
    return s;
}

void printdupSubtree(node *root){

    unordered_map<string, int> m;
    inorder(root, m);
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4); 
    root->right->left = new node(2);
    root->right->left->left = new node(4);
    root->right->right = new node(4);

    printdupSubtree(root);

}