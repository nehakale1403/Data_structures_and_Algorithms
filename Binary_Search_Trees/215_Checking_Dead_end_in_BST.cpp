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

bool solve(node* root, int min, int max){
    if(!root) return false;

    if(min==max) return true;

    return solve(root->left, min, root->data-1) or solve(root->right, root->data+1, max);
}

bool checkDeadEnd(node* root){
    return solve(root, 1, INT_MAX);
}

int main(){

    node* root = new node(11);
    root->left = new node(10);
    root->right = new node(12);

    if(checkDeadEnd(root)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

}

