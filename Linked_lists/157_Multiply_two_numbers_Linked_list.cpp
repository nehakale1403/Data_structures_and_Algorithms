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

void multiply(node* &first, node* &second){

    long long num1=0, num2=0;
    while(first||second){
        if(first){
            num1  = num1*10 + first->data;
            first = first->next;
        }
        if(second){
            num2 = num2*10+second->data;
            second = second->next;
        }
    }
    cout<<num1*num2<<endl;
}

int main(){

    node *first = NULL;
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        insertAtTail(first, x);
    }
    node *second = NULL;
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x;
        insertAtTail(second, x);
    }

    multiply(first, second);
    
    return 0;
}
