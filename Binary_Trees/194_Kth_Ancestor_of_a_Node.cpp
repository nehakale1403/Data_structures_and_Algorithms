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
node* temp = NULL;
node* kthAncestor(node* root, int n, int &k){

    //  first find the node and then backtrack to the kth parent.
    
    if(!root) return NULL;

    if(root->data == n || (temp = kthAncestor(root->left, n, k)) || (temp = kthAncestor(root->right, n, k))){

        if(k>0){
            k--;
        }else if(k==0){
            cout<<root->data;
            return NULL;
        }
        return root;
    }
    
    
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int n, k;
    cin>>n>>k;
    node* res = kthAncestor(root, n, k);
    cout<<res->data;
    
}