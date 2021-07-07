#include<bits/stdc++.h>
using namespace std;

int start = 0;

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

void preOrderRecursive(node* root){

    if(root == NULL)
        return;
    
    cout<<root->data<<" "; 
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);

}

node* str2treemain(string s){
    

    if(start>=s.length())
        return NULL;
    
    int num = 0;
    while(start<s.length() && isdigit(s[start])){
        
        int digit = s[start] - '0';
        num = num*10 +digit;
        start++;
    }

    node* root = new node(num);
    if(start>=s.length())
        return root;
    
    if(start<s.length() && s[start] == '('){
        start++;
        root->left = str2treemain(s);
    }
    
    if(start<s.length() && s[start] == ')'){
        start++;
        return root;
    }
    if(start<s.length() && s[start] == '('){
        start++;
        root->right = str2treemain(s);
    }
    
    if(start<s.length() && s[start] == ')'){
        start++;
        return root;
    }
    return root;

}

node* strtotree(string s){
    if(s.length()== 0)
        return NULL;
    
    return str2treemain(s);
}

int main(){

    string s;
    cin>>s;
    

    node *root = strtotree(s);
    
    preOrderRecursive(root);
}