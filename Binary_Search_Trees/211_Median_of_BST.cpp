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

void countNodes(node* root, int &n){

    if(!root)
        return;
    countNodes(root->left, n);
    n++;
    countNodes(root->right, n);

}

void func(node* root, node* &curr, node* &prev, int &c, int k, int &flag){

    if(!root){
        return;
    }

    func(root->left, curr, prev, c, k, flag);

    if(prev == NULL){
        prev = root;
        c++;
    }else if(c == k){
        c++;
        curr = root;
        flag = 1;
        return;
    }else if(flag == 0){
        c++;
        prev = root;
    }
    func(root->right, curr, prev, c, k, flag);
}

float findMedian(node* root){

    int n=0;
    countNodes(root, n);
    node* prev=NULL, *curr=NULL;
    int c=1;
    int x = (n/2)+1;
    int flag=0;

    func(root, curr, prev, c, x, flag);
    
    if(n&1){
        float ans = (curr->data)*1.0;
        return ans;
    }else{
        float ans = ((curr->data + prev->data)*1.0)/(2*1.0);
        return ans;
    }
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);
    
    cout<<findMedian(root);

}

