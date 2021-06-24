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

void divideIntoTwo(node* &head){
    
    node *fast, *slow;
    fast = head->next;
    slow = head;
    while(fast->next!=head){
        fast = fast->next;
        slow = slow->next;
        if(fast->next!=head)
            fast = fast->next;
    }

    node* head1, *head2;
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    fast->next = head2;
    display(head1);
    display(head2);
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
    display(head);
    makeCircular(head);
    divideIntoTwo(head);
}