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

void removeDuplicates(node* &head){
    
    node *p, *q;
    p = head->next;
    q = head;
    while(p!=NULL){
        if(q->data == p->data){
            q->next = p->next;
            p = q->next;
        }else{
            q = p;
            p = p->next;
        }
    }
    
}

int main(){

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    // display(head);
    removeDuplicates(head);
    display(head);
    return 0;
}