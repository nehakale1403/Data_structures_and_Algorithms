#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;

    node(int val){
        prev=NULL;
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){

    node *temp = new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = temp;
    temp->prev=p;
}

void display(node* &head){

    node *p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void pairsWithSum(node* &head, int key){
    
    node *left = head;
    node *right = head;

    while(right->next!=NULL)
        right = right->next;

    bool found = false;
    while(left!=right && right->next!=left){

        if((left->data+right->data) == key){

            cout<<left->data<<" "<<right->data<<endl;
            found = true;
            left = left->next;
            right = right->prev;

        }else if((left->data+right->data) > key){

            right = right->prev;

        }else{

            left = left->next;
            
        }
    }

    if(!found)
        cout<<"No pair found"<<endl;
}

int main(){
    node *head = NULL;
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        insertAtTail(head, x);
    }
    int k;
    cin>>k;
    pairsWithSum(head, k);

}