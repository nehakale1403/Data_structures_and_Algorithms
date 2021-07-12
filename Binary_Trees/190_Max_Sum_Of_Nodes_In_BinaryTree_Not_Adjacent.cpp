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

unordered_map<node*, int> dp;

int maxSum(node* root){
    
    if(!root) return 0;

    if(dp[root]) return dp[root];

    int inc = root->data;
    if(root->left){
        inc+=maxSum(root->left->left);
        inc+=maxSum(root->left->right);
    }
    if(root->right){
        inc+=maxSum(root->right->left);
        inc+=maxSum(root->right->right);
    }

    int exc = maxSum(root->left) + maxSum(root->right);

    dp[root] = max(inc, exc);

    return dp[root];
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<maxSum(root);
    
}