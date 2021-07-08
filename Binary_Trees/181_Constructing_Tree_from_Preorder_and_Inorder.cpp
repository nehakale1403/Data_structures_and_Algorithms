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
int search(int in[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(in[i] == curr){
            return i;
        }
    }
    return -1;
}

void inorder(node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* treeFromPreIn(int pre[], int in[], int start, int end){
    static int idx = 0;

    if(start>end) return NULL;

    int curr = pre[idx];
    idx++;
    node* temp = new node(curr);

    if(start == end){
        return temp;
    }

    int pos= search(in, start, end, curr);
    temp->left = treeFromPreIn(pre, in, start, pos-1);
    temp->right = treeFromPreIn(pre, in, pos+1, end);

    return temp;
}


int main(){

    int n;
    cin>>n;
    int pre[n];
    int in[n];

    for(int i=0; i<n; i++) cin>>pre[i];
    for(int i=0; i<n; i++) cin>>in[i];


    node* root = treeFromPreIn(pre, in, 0, n-1);

    inorder(root);
    
}