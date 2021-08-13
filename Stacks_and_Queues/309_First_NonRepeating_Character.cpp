#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256

class node{
    public:
    node *prev;
    char data;
    node *next;

    node(int val){
        prev=NULL;
        data = val;
        next = NULL;
    }
};

void deleteNode(node* &head, node* &tail, node *temp){
            if (head == NULL) 
        		return; 
        
        	if (head == temp) 
        	    head = head->next; 
        	if (tail == temp) 
        		tail = tail->prev; 
        	if (temp->next != NULL) 
        		temp->next->prev = temp->prev; 
        	if (temp->prev != NULL) 
        		temp->prev->next = temp->next; 
        
        	delete (temp); 
        }

void insertAtTail(node* &head, node* &tail, char val){

        node *temp = new node(val);
        if(head==NULL){
            head=temp;
            tail = temp;
            return;
        }
        node *p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = temp;
        tail = temp;
        temp->prev=p;
        
}

void firstNonRepeatingChar(string s){

    node* inDLL[MAX_CHAR];
    bool repeated[MAX_CHAR];
    node* head = NULL, *tail = NULL;

    for(int i=0; i<s.length(); i++){
        inDLL[i] = NULL;
        repeated[i]= false;
    }

    for(int i=0; i<s.length(); i++){
        char x = s[i];
        if(!repeated[x]){
            if(inDLL[x] == NULL){
                insertAtTail(head, tail, s[i]);
                inDLL[x] = tail;
            }else{
                deleteNode(head, tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;
            }
        }
        if(head!=NULL){
            cout<<head->data;
        }else{
            cout<<"#";
        }
        
    }
}

int main(){
    string s;
    cin>>s;

    firstNonRepeatingChar(s);
}