#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

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

void makeCircular(node* &head){

    node*p = head;
    while(p->next!=NULL)
        p = p->next;
    p->next = head;
}

void deleteKey(node* &head, int key){
    
    if(head == NULL)
        return;
    
    if(head->data == key && head->next == head){
        free(head);
        head=NULL;
        return;
    }

    node*last = head;
    if(head->data == key){
        while(last->next != head)
            last = last->next;
        
        last->next = head->next;
        free(head);
        head = last->next;
    }

    node *p, *q;
    p = head;
    while(p->next!=head){
        if(p->next->data == key){
            q = p->next;
            p->next = q->next;
            free(q);
            return;
        }
        p = p->next;
    }  

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
    int key;
    cin>>key;
    display(head);
    makeCircular(head);
    deleteKey(head, key);
    display(head);
}