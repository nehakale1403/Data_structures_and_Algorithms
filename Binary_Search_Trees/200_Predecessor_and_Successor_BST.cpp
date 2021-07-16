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

void findPreSuc(node* root, int k, node* &pre, node* &suc){

    if(!root) return;

    if(root->data == k){

        if(root->left!=NULL){
            node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }

        if(root->right!=NULL){
            node* temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if(root->data > k){
        suc = root;
        findPreSuc(root->left, k, pre, suc);
    }else{
        pre = root;
        findPreSuc(root->right, k, pre, suc);
    }
    
    
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    int k;
    cin>>k;

    node* pre, *suc;
    findPreSuc(root, k, pre, suc);

    cout<<pre->data<<" "<<suc->data<<endl;
}

