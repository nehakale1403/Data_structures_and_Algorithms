#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
};
struct Node *head=NULL;
// 2..8..0..1
void createNode(int num){
    struct Node *p = new Node; //1
    p->data = num;
    p->next = NULL; 
    if(head == NULL){ 
        head=p; 
    }else{
        struct Node *i=head;
        while(i->next != NULL){
            i = i->next;
        }
        i->next = p;
    }
}

void display(){
    struct Node *ptr = head;
    while(ptr !=NULL){
        cout<<ptr->data;
        ptr = ptr->next;
    }       
}

int findKey(int key){

    struct Node *ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data == key){
            return count;
        }
        count++;
        ptr = ptr->next;
    }
    return -1;
}


int main(){
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        createNode(num);
    }
    // display();
    int key;
    cin>>key;
    cout<<findKey(key);
        
    return 0;
}
