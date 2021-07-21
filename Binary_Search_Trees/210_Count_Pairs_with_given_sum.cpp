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

int pairSum(node* root1, node* root2, int x){

    if(!root1 || !root2)
        return 0;

    int count=0;
    
    stack<node*> st1, st2;
    node* top1, *top2;

    while(1){
        while(root1 != NULL){
            st1.push(root1);
            root1 = root1->left;
        }
        while(root2!=NULL){
            st2.push(root2);
            root2 = root2->right;
        }

        if(st1.empty() || st2.empty())
            break;
        
        top1 = st1.top();
        top2 = st2.top();

        if(top1->data + top2->data  == x){
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }else if((top1->data + top2->data) < x){
            st1.pop();
            root1 = root1->right;
        }else{
            st2.pop();
            root2 = root2->left;
        }
    }
    return count;
}

int main(){

    node* root1 = new node(4);
    root1->left = new node(2);
    root1->right = new node(6);

    node* root2 = new node(5);
    root2->left = new node(3);
    root2->right = new node(7);
    
    int k;
    cin>>k;
    cout<<pairSum(root1, root2, k);

}

