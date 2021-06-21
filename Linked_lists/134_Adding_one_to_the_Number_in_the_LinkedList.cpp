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

void add1(node* &head){

    reverse(head);

    node *p = head, *q=NULL;

    int carry=1, sum;
    while(p!=NULL){
        sum = carry+p->data;
        if(sum>=10){
            carry=1;
        }else{
            carry=0;
        }
        sum = sum%10;
        p->data = sum;
        q=p;
        p = p->next;

    }

    if(carry>0){
        node *temp = new node(carry);
        q->next = temp;
    }
    reverse(head);
}

int main(){

    node *head = NULL;
    insertAtTail(head, 4);
    insertAtTail(head, 9);
    insertAtTail(head, 4);
    insertAtTail(head, 9);
    display(head);
    add1(head);
    display(head);
    
    return 0;
}