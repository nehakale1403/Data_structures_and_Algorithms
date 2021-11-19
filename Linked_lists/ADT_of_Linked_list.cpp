#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    
        Node(int val){
            data = val;
            next = NULL;
        }

       
};

void insertAtTail(Node* &head, int val){

    Node *temp = new Node(val);
    if(head == NULL){
        head = temp;
    }else{
        // head 1 2 3 4 5->NULL
        Node * p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void display(Node *head){
    Node *p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void insertAtHead(Node *&head, int val){
    Node* temp = new Node(val);

    temp->next = head;
    head = temp;
}

void deleteData(Node *&head, int val){
    Node *p = head, *q = NULL;
    while(p->data != val){
        q = p;
        p = p->next;
    }
    q->next = q->next->next;
    delete(p);
}

void insertAtPosition(Node* &head, int val, int pos){

    Node *temp = new Node(val);
    if(pos == 1){
        temp->next = head;
        head = temp;
        return;
    }

    int count = 1;
    Node* p = head;
    while(count != pos-1){
        if(p == NULL){
            cout<<"Cannot insert"<<endl;
            return;
        }
        p = p->next;
        count++;
    }

    
    temp->next = p->next;
    p->next = temp;
}

int main(){


    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);

    insertAtPosition(head, 6, 4);
    display(head);
}
