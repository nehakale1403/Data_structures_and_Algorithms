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

node* insertInBST(node* &root, int k, node* &succ){

    if(root==NULL)
        return root = new node(k);
    
    if(k<root->data){
        succ = root;
        root->left = insertInBST(root->left, k, succ);
    }else if(k>root->data){
        root->right = insertInBST(root->right, k, succ);
    }
    return root;
}

void replace(int arr[], int n){
    node* root = NULL;

    for(int i=n-1; i>=0; i--){
        node* succ = NULL;

        root = insertInBST(root, arr[i], succ);

        if(succ)
            arr[i] = succ->data;
        else
            arr[i] = -1;
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    node* root =NULL;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }   
    replace(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } 
}

