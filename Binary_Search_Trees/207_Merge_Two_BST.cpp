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

void inorder(node* root){

    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

vector<int> arr1, arr2;

void storeInorder(node* root, vector<int> &temp){

    if(!root) return;

    storeInorder(root->left, temp);
    temp.push_back(root->data);
    storeInorder(root->right, temp);
}

void mergeArrays(vector<int> arr1, vector<int> arr2, vector<int> &resArr){

    int i=0, j=0, k=0;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] <arr2[j]){
            resArr.push_back(arr1[i]);
            i++;
        }else{
            resArr.push_back(arr2[j]);
            j++;
        }
        k++;
    }

    while(i<arr1.size()){
        resArr.push_back(arr1[i]);
        i++;
    }

    while(j<arr2.size()){
        resArr.push_back(arr2[j]);
        j++;
    }
    
}
node* sortedArrayToBST(vector<int> arr, int start, int end){

    if(start>end)
        return NULL;

    int mid = (start+end)/2;
    node* root = new node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}
node* mergeTrees(node* root1, node* root2){

    storeInorder(root1, arr1);
    storeInorder(root2, arr2);

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> resArr;
    mergeArrays(arr1, arr2, resArr);

    return sortedArrayToBST(resArr, 0, resArr.size()-1);
    
}

int main(){
    node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);

    node* root2 = new node(5);
    root2->left = new node(4);
    root2->right = new node(6);

    node* ans = mergeTrees(root1, root2);

    inorder(ans);
}