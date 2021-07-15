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

bool searchNode(node* root, int k){
    if(!root) return false;

    if(root->data == k){
        return true;
    }
    if(k<root->data)
        return searchNode(root->left, k);
    else if(k>root->data)
        return searchNode(root->right, k);
    
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
    if(searchNode(root, k)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

