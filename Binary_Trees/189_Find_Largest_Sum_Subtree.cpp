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

int solve(node* root, int &ans){

    if(root == NULL)
        return 0;

    int currSum = root->data + solve(root->left, ans) + solve(root->right, ans);

    if(currSum>ans){
        ans = currSum;
    }
    
    return currSum;
}


int largestSumSubtree(node* root){
    
    if(!root) return 0;

    int ans = INT_MIN;

    solve(root, ans);

    return ans;
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(-16);
    root->right->right = new node(7);

    cout<<largestSumSubtree(root);
    
}