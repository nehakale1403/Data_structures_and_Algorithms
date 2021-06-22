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

void intersection(node* &first, node* &second){
    
    node *res = NULL;
    node *p, *q, *r;
    p = first;
    q = second;
    r = res;

    while(p!=NULL && q!=NULL){

        if(p->data < q->data){
            p = p->next;
        }else if(q->data < p->data){
            q = q->next;
        }else if(p->data == q->data){
            node *temp = new node(p->data);
            if(res == NULL)
                res = temp;
            else    
                r->next = temp;
            r = temp; 
            p = p->next;
            q = q->next;     
        }
    }
    display(res);
    
}

int main(){

    node *first = NULL;
    insertAtTail(first, 1);
    insertAtTail(first, 2);
    insertAtTail(first, 3);
    insertAtTail(first, 4);
    insertAtTail(first, 6);

    node *second = NULL;
    insertAtTail(second, 2);
    insertAtTail(second, 4);
    insertAtTail(second, 6);
    insertAtTail(second, 8);

    intersection(first, second);
    
    return 0;
}