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

void sort012(node* &head){

    int count[3] = {0};
    node *p = head;

    while(p!=NULL){
        count[p->data] +=1;
        p = p->next;
    }

    int i=0;
    p = head;

    while(p!=NULL){
        if(count[i] == 0){
            i++;
        }else{
            p->data = i;
            count[i]--;
            p = p->next;
        }
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
    sort012(head);
    display(head);
}