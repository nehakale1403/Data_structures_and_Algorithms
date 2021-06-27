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

node* reverseGroups(node* &head, int k){
    
    if(!head)
        return NULL;
    
    node *temp, *curr = head, *newhead;
    int count=0;
    while(curr!=NULL && count<k){
        newhead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    if(count>=k){
        head->next = reverseGroups(curr, k);
    }
    return newhead;
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
    node *newhead = reverseGroups(head, k);
    display(newhead);
}