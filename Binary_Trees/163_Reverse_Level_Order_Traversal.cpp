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

void reverseLevelOrder(node* root){

    if(root == NULL)
        return;
    
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* t = q.front();
        ans.push_back(t->data);
        if(t->right)
            q.push(t->right);
        
        if(t->left)
            q.push(t->left);
        
        q.pop();
    }
    reverse(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
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
    

    reverseLevelOrder(root);
    
}