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

node* reverseGroups(node* &head, int k){
    
    node *r, *q, *p;
    r = NULL;
    q = head;
    
    int count=0;
    while(q != NULL && count<k){

        p = q->next;
        q->next = r;
        r = q;
        q = p;
        count++;
    }
    
    if(p != NULL)
        head->next = reverseGroups(p, k);
    
    return r;
}

int main(){

    int k;
    cin>>k;
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    node *newhead = reverseGroups(head, k);
    display(newhead);
    
    return 0;
}