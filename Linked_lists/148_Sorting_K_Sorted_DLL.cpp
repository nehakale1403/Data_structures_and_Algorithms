#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;

    node(int val){
        prev=NULL;
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){

    node *temp = new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = temp;
    temp->prev=p;
}

void display(node* &head){

    node *p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

struct compare{
    bool operator()(node* first, node* second){
        return first->data > second->data;
    }
};

void sort(node* &head, int k){
    
    if(head == NULL)
        return;
    
    priority_queue<node*, vector<node*>, compare> pq;

    node *newhead=NULL, *curr;

    for(int i=0; head!=NULL && i<=k; i++){
        pq.push(head);
        head = head->next;
    }

    while(!pq.empty()){

        if(newhead == NULL){
            newhead = pq.top();
            newhead->prev = NULL;
            curr = newhead;
        }else{
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }

        pq.pop();
        if(head!=NULL){
            pq.push(head);
            head = head->next;
        }
    }
    curr->next = NULL;

    display(newhead);

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
    sort(head, k);
    display(head);
}