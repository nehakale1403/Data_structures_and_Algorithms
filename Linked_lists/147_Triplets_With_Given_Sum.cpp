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

int countPairs(node *first, node *second, int key){

    int count=0;
    while(first!=NULL && second!=NULL && first!=second && second->next!=first){

        if((first->data+second->data) == key){

            count++;
            first = first->next;
            second = second->prev;

        }else if((first->data+second->data) > key){

            second = second->prev;

        }else{

            first = first->next;
            
        }
    }
    return count;
}

int tripletsWithSum(node* &head, int key){
    
    if(head == NULL)
        return 0;
    
    node *curr, *first, *last;
    int count=0;
    last = head;
    while(last->next!=NULL)
        last = last->next;
    
    for(curr = head; curr!=NULL; curr=curr->next){
        first = curr->next;
        count+=countPairs(first, last, key-curr->data);
    }

    return count;
    
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
    cout<<tripletsWithSum(head, k);

}