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

void postOrderRecursive(node* root){

    if(root == NULL)
        return;
     
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout<<root->data<<" "; 

}

void postOrderIterative(node *root){

    if(root == NULL)    
        return;
    
    stack<node*> st;
    st.push(root);

    stack<int> res;
    while (!st.empty()){

        node *curr = st.top();
        st.pop();
        res.push(curr->data);

        if(curr->left){
            st.push(curr->left);
        }
        if(curr->right){
            st.push(curr->right);
        }
        
    }
    
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
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
    

    postOrderRecursive(root);
    cout<<endl;
    postOrderIterative(root);
    
}