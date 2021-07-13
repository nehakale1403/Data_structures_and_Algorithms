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

void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void solve(node* root, vector<int> &path, int k){
    if(!root) return;

    path.push_back(root->data);
    solve(root->left, path, k);
    solve(root->right, path, k);

    int f=0;
    for(int j=path.size()-1; j>=0; j--){
        f+=path[j];
        if(f == k)
            printVector(path, j);
    }
    path.pop_back();
}

void pathSumK(node* root, int k){
    
    vector<int> path;
    solve(root, path, k);
    
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int k;
    cin>>k;
    pathSumK(root, k);
    
}