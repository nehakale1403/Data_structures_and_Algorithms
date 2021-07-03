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

void mirror(node* root){

    if(root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
    
}

void levelOrder(node* root){

    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* p = q.front();
        q.pop();
        if(p!=NULL){
            cout<<p->data<<" ";
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
        }else if(!q.empty()){
            q.push(NULL);
        }
    }

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    

    mirror(root);
    levelOrder(root);
}