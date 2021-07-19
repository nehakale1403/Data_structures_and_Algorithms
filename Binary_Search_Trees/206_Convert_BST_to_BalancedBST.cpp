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

void inorder(node* root){

    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

vector<node*> temp; 
node* root;
void storeInorder(node* root, vector<node*> &temp){

    if(!root) return;

    storeInorder(root->left, temp);
    temp.push_back(root);
    storeInorder(root->right, temp);
}

node* solve(node* root, int start, int end){
    if(start>end)
        return NULL;
    
    int mid = (start+end)/2;
    root = temp[mid];

    root->left = solve(root, start, mid-1);
    root->right = solve(root, mid+1, end);

    return root;
    
}

node* balanceTree(node* &root){

    
    storeInorder(root, temp);

    int start = 0, end = temp.size()-1;

    return solve(root, start, end);
    
}

int main(){

    node* root = new node(10);
    root->left = new node(20);
    root->left->left = new node(30);

    node* r = balanceTree(root);

    inorder(r);
}

