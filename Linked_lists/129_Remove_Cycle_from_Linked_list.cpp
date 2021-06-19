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

void makeCycle(node* &head, int pos){
    
    node *temp = head;
    node *startNode;
    int count=1;

    while(temp->next != NULL){
        if(count == pos){
            startNode = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node* &head){

    //hare and tortoise algorithm
    //moving q by 2 nodes and p by 1 node
    node *p, *q;
    p = q =  head;
    while(q!=NULL && q->next !=NULL){
        p = p->next;
        q = q->next->next;
        if(p == q)
            return true;   
    }
    return false;

}

void removeCycle(node* &head){

    node *fast = head;
    node *slow = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}



int main(){

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    makeCycle(head, 2);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    return 0;
}