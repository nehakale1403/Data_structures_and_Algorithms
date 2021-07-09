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

void inOrderRecursive(node* root){

    if(root == NULL)
        return;
    inOrderRecursive(root->left);
    cout<<root->data<<" "; 
    inOrderRecursive(root->right);

}

void inOrder(int arr[], vector<int> &v, int n, int index){
    if(index>=n)
        return;
    inOrder(arr, v, n, 2*index+1);
    v.push_back(arr[index]);
    inOrder(arr, v, n, 2*index+2);
}

int minSwaps(vector<int> &v){

    vector<pair<int, int>> t(v.size());
    int ans = 0;
    for(int i=0; i<v.size(); i++)
        t[i].first = v[i], t[i].second = i;
    
    sort(t.begin(), t.end());
    for(int i=0; i<t.size(); i++){
        if(i == t[i].second)
            continue;
        else{
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        if(i!=t[i].second)
            i--;
        ans++;
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> v;
    inOrder(arr, v, n, 0);
    
    cout<<minSwaps(v);
    
}