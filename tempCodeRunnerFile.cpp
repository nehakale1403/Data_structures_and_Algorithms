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
}

void insertAtHead(Node *&head, int val){
    Node* temp = new Node(val);

    temp->next = head;
    head = temp;
}

int main(){


    Node *head = NULL;
    insertAtHead(head, 2);


    display(head);

}

//head->4 ->2 -> NULL