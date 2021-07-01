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

void kthNodeFromEnd(node* &head, int k){

    reverse(head);
    int count=1;
    node *p = head;
    while(count!=k){
        
        p= p->next;
        count++;
        if(p == NULL){
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<p->data;
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
    kthNodeFromEnd(head, k);
    
    return 0;
}
