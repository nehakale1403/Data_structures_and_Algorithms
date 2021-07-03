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

void inOrderRecursive(node* root){

    if(root == NULL)
        return;
    inOrderRecursive(root->left);
    cout<<root->data<<" "; 
    inOrderRecursive(root->right);

}

void inOrderIterative(node *root){

    if(root == NULL)    
        return;
    
    stack<node*> st;
    node *p = root;

    while (!st.empty() || p!=nullptr){

        if(p != nullptr){            
            st.push(p);
            p = p->left;
        }else{           
            p = st.top();
            st.pop();
            cout<<p->data<<" ";
            p = p->right;
        }
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
    

    inOrderRecursive(root);
    inOrderIterative(root);
    
}