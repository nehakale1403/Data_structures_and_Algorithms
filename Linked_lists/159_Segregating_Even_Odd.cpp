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

void segregateEvenOdd(node* &head, int n){

    node *curr = head;
    node *prev = NULL;
    node *end = head;
    int count=0;
    
    while(end->next!=NULL){
        end = end->next;
    }
    
    node *new_end = end;
    while(curr->data%2 != 0 && curr!=end){
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
    if(curr->data%2 == 0){
        head = curr;
        while(curr!=end){
            if(curr->data%2 == 0){
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                new_end->next = curr;
                curr->next = NULL;
                new_end = curr;
                curr = prev->next;
            }
        }
    }else{
        prev = curr;
    }

    if(new_end!=end && end->data%2 != 0){
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }

    display(head);
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

    segregateEvenOdd(head, n);
    
    return 0;
}
