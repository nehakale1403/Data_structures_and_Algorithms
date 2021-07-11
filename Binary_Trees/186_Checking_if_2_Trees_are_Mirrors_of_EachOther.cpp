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
void preorder(node *root1,stack<int> &st){

    if(root1==NULL)
        return;
    st.push(root1->data);
    preorder(root1->left, st);
    preorder(root1->right, st);
}


void postorder(node* root2, queue<int> &q){
    if(root2 == NULL)
        return;
    postorder(root2->left, q);
    postorder(root2->right, q);
    q.push(root2->data);
}
int checkMirrorTree(node* root1, node* root2){

    stack<int> st;
    queue<int> q;

    preorder(root1, st);
    postorder(root2, q);
    

    while(!q.empty()){
        int a = st.top();
        int b = q.front();
        cout<<a<<" "<<b<<endl;
        if(a!=b){
            return 0;
        }
        st.pop();
        q.pop();
    }
    return 1;
}

int main(){
    
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    node *root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);

    cout<<checkMirrorTree(root1, root2);

    
}