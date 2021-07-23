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

void postorder(node* root){

    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

node* constructTreeUtil(int pre[], int &preIndex, int key, int min, int max, int n){

    cout<<"inserting "<<key<<endl;
    if(preIndex>=n)
        return NULL;

    node* root = NULL;

    if((key > min) && (key < max)){

        root = new node(key);
        preIndex = preIndex + 1;

        if(preIndex < n){
            root->left = constructTreeUtil(pre, preIndex, pre[preIndex], min, key, n);
        }
        if(preIndex < n){
            root->right = constructTreeUtil(pre, preIndex, pre[preIndex], key, max, n);
        }
    }
    return root;
}

node* constructTree(int pre[], int n){

    int preIndex = 0;
    return constructTreeUtil(pre, preIndex, pre[0], INT_MIN, INT_MAX, n);
}



int main(){

    int n;
    cin>>n;

    int pre[n];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }   
    node* ans = constructTree(pre, n);
    postorder(ans);
}

