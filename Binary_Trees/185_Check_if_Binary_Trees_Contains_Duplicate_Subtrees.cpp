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

unordered_map<string, int> m;

string solve(node *root){

    if(!root) return "$";

    string s="";
    //if the node is a leaf node
    if(!root->right and ! root->left){
        s = to_string(root->data);
        return s;
    }
    s = s+to_string(root->data);
    s = s+ solve(root->left);
    s = s+ solve(root->right);
    m[s]++;
    return s;
}

bool dupSubtree(node *root){
    m.clear();
    solve(root);
    for(auto x:m){
        if(x.second>=2) return true;
    }
    return false;
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(4);
    root->right->right = new node(5);

    if(dupSubtree(root))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    
}