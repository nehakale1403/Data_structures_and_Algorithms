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

int sum(node* root){

    if(root == NULL)
        return 0;
    
    return(sum(root->left) + root->data + sum(root->right));

}

int sumTree(node *root){

    int ls, rs;

    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 1;
    
    ls = sum(root->left);
    rs = sum(root->right);

    if((root->data == ls+rs) && sumTree(root->left) && sumTree(root->right))
        return 1;
    
    return 0;
 
}

int main(){

    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(5);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    
    if(sumTree(root)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}