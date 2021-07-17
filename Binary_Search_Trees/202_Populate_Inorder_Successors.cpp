#include<bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node *left;
    node *right;
    node *next;
};
 
void solve(node* root, node* &prev){
    if(!root) return;

    solve(root->left, prev);

    if(prev!=NULL){
        prev->next = root;
    }
    prev = root;
    solve(root->right, prev);
}

void populateNext(node* root){
    node* prev = NULL;

    solve(root, prev);
}
    

 
node* newnode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;
 
    return(Node);
}

int main()
{
 
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);
 
    // Populates nextRight pointer in all nodes
    populateNext(root);
 
    // Let us see the populated values
    node *ptr = root->left->left;
    while(ptr)
    {
        
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)
             << endl;
        ptr = ptr->next;
    }
 
    return 0;
}