#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){

    node *temp = new node(val);

    if(head == NULL){
        head = temp;
        return;
    }
        

    node* p = head;

    while(p->next != NULL)
        p = p->next;
    
    p->next = temp;
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
    
    node *p, *q, *r;
    p = head;
    q = r = NULL;

    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

int main(){

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    reverse(head);
    display(head);
    
    return 0;
}