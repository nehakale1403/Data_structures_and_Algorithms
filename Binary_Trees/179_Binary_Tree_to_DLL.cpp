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

void printDLL(node* head){
    node*p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->right;
    }
}

void solve(node* root, node* &head, node* &prev, int &f){
    if(!root) return;

    solve(root->left, head, prev, f);
    if(f == 0){
        f=1;
        head = root;
        prev = root;
    }else{
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    solve(root->right, head, prev, f);
}

node* convertToDLL(node* root){
    node* head = NULL;
    node* prev = NULL;

    int f = 0;
    solve(root, head, prev, f);
    return head;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    node* head = convertToDLL(root);
    printDLL(head);
    
    
}