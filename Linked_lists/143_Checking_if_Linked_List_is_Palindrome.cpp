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

bool checkPalindrome(node* &head, int n){

    if(head == NULL || head->next == NULL)
        return true;
    
    //getting the middle element
    node *fast, *slow;
    fast = head->next;
    slow = head;
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
        if(fast->next!=NULL)
            fast = fast->next;
    }

    //reversing the list from middle;
    // cout<<slow->data<<" "<<fast->data<<endl;
    reverse(slow->next);

    //checking if they are equal
    node *p = head;
    node *q = slow->next;
    
    if(n%2 == 0){
        while(q!=NULL){
            if(p->data == q->data){
                p = p->next;
                q = q->next;
            }else{
                return false;
            }
        }
        return true;
    }else{
        
        while(p!=slow){
            if(p->data==q->data){
                p = p->next;
                q = q->next;
            }else{
                return false;
            }
        }
        return true;
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
    if(checkPalindrome(head, n)){
        cout<<"Is Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;
    }
    
}