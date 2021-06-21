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
    p = head;
    q = NULL;
    unordered_set<int> set;
    while(p!=NULL){
        if(set.find(p->data) != set.end()){
            q->next = p->next;
            delete(p);
            p = q->next;
        }else{
            set.insert(p->data);
            q = p;
            p = p->next;
        }
    }
    
}

int main(){

    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    removeDuplicates(head);
    display(head);
    return 0;
}