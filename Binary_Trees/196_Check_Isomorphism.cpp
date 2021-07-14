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

bool checkIsomorphism(node* root1, node* root2){

    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 == NULL || root2 == NULL)
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    return(checkIsomorphism(root1->left, root2->left) && checkIsomorphism(root1->right, root2->right)||
           checkIsomorphism(root1->left, root2->right) && checkIsomorphism(root1->right, root2->left));
}

int main(){
    
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    node *root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);

    if(checkIsomorphism(root1, root2)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    
}