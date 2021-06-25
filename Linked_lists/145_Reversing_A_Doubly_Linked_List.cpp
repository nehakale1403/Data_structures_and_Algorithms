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

void reverse(node* &head){
    node *p=head;
    node *q=NULL;
    
    while(p!=NULL){

        q = p->prev;
        p->prev = p->next;
        p->next = q;
        p = p->prev;
    }
    if(q!=NULL)
        head = q->prev;
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
    reverse(head);
    display(head);
}