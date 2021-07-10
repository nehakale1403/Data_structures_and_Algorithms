#include<bits/stdc++.h>
using namespace std;

int ans;

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

void solve(node* root, int h, int &ma){
    if(!root)   return;
    if(ans == 0) return;
    if(!root->left && !root->right){
        if(ma == -1){
            ma = h;
        }else{
            if(h!=ma){
                ans=0;
            }
        }
        return;
    }
    solve(root->left, h+1, ma);
    solve(root->right, h+1, ma);
}


bool sameLevel(node *root){

    int ma = -1;
    int h=0;
    ans = 1;
    solve(root, h, ma);
    return ans;
    
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    
    cout<<sameLevel(root);
}