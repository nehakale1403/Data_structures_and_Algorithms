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

void deleteNodes(node* &head){

    reverse(head);

    node *r = NULL;
    node *p = head;
    node *q = NULL;
    int max = 0;
    while(p!=NULL){
        if(p->data>=max){
            max = p->data;
            q = p;
            p = p->next;
        }else{
    
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
    reverse(head);
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

    deleteNodes(head);
    
    return 0;
}
