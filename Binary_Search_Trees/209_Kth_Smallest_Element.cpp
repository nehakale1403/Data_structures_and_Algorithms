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

void kthSmallestUtil(node* root, int k, int &count){

    if(root == NULL || count>=k)
        return;
    
    kthSmallestUtil(root->left, k, count);
    count++;
    if(count==k){
        cout<<root->data<<endl;
        return;
    }
    kthSmallestUtil(root->right, k, count);
}

void kthSmallest(node* root, int k){

    int count=0;

    kthSmallestUtil(root, k, count);
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

    kthSmallest(root, k);
}