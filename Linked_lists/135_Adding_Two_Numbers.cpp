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

void add(node* &first, node* &second){

    reverse(first);
    reverse(second);

    node *res = NULL;

    node *p, *q, *r;
    p = first;
    q = second;
    r = res;
 
    int carry=0, sum;

    while(p!=NULL || q!=NULL){

        sum = carry + (p ? p->data:0) + (q ? q->data:0);
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;
        node *temp = new node(sum);
         
        if(res == NULL){
            res = temp;
        }else{
            r->next = temp;
        }
        r = temp;
    
        if(p!=NULL)
            p = p->next;

        if(q!=NULL)
            q = q->next;
            
    }

    if(carry>0){
        node *temp = new node(carry);
        r->next = temp;
    }
    reverse(res);
    display(res);

}

int main(){

    node *first = NULL;
    insertAtTail(first, 9);
    insertAtTail(first, 9);
    insertAtTail(first, 9);

    node *second = NULL;
    insertAtTail(second, 2);
    insertAtTail(second, 4);
    insertAtTail(second, 5);

    add(first, second);
    
    return 0;
}
