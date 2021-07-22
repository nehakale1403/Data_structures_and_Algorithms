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

void countNodes(node* root, int &count, int l, int r){

    if(!root)
        return;
    countNodes(root->left, count, l, r);
    if((root->data>=l) && (root->data<=r))
        count++;
    countNodes(root->right, count, l, r);

}

int countInRange(node* root, int l, int r){
    int count=0;
    countNodes(root, count, l, r);
    return count;
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);
    
    int l, r;
    cin>>l>>r;
    cout<<countInRange(root, l, r);

}

