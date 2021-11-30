#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree{
    public:
    Node* root;

    void inorder(Node* root){
        if(!root){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    Node* insertElement(Node* root, int data){
        cout<<"here"<<endl;
        if(root == NULL){
            return new Node(data);
        }else if(root->data == data){
            return root;
        }else if(root->data > data){
            root->left = insertElement(root->left, data);
        }else{
            root->right = insertElement(root->right, data);
        }
    }
};

int main(){

    Tree t;
    t.insertElement(t.root, 2);
    t.insertElement(t.root, 3);
    t.insertElement(t.root, 1);

    t.inorder(t.root);
}