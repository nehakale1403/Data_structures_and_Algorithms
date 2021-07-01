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

    node *p = head;
    node *q = NULL;
    node *odd = head;
    int count=0;
    
    while(odd->next!=NULL){
        odd = odd->next;
    }
    while(p!=NULL && count<n){
    
        if(p->data %2 == 0){
            q = p;
            p = p->next;
            
        }else{
            if(p == head){
                head = p->next;
                odd->next = p;
                p->next = NULL;
                odd = p;
                p = head;
            }else{
                q->next= p->next;
                odd->next = p;
                p->next = NULL;
                odd = p;
                p = q->next;
            }
        }
        count++;
        display(head);
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
