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

void solve(node* root, int sum,int len,int &max_sum, int &max_len){

    if(!root){
        if(max_len<len){
            max_len = len;
            max_sum = sum;
        }else if(max_len == len && max_sum<sum){
            max_sum = sum;
        }
        return;
    }
    solve(root->left, sum+root->data, len+1, max_sum, max_len);
    solve(root->right, sum+root->data, len+1, max_sum, max_len);
}


int sumOfLongestPathUtil(node* root){
    
    if(!root) return 0;

    int max_sum = INT_MIN, max_len = 0;

    solve(root, 0,0, max_sum, max_len);
    return max_sum;
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->right = new node(1);

    cout<<sumOfLongestPathUtil(root);
    
}