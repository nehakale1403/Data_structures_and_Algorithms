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

class Stack{
    
    Node* top;
    public:
        Stack(){
            top = NULL;
        }
        void push(int val){
            Node* temp = new Node(val);

            temp->next = top;
            top = temp;

        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            Node*p = top;
            top = top->next;
            delete(p);
        }

        bool isEmpty(){
            if(top == NULL)
                return true;
            else
                return false;
        }

        void display(){
            Node *p = top;
            while(p!=NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }

        void size(){
            int count = 0;
            Node *p = top;
            while(p!=NULL){
                count++;
                p = p->next;
            }
            cout<<count<<endl;
        }

        void peek(){
            cout<<top->data<<" ";
        }
    
};

int main(){

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.display();
    s1.pop();
    s1.size();
    s1.display();
    s1.pop();
    s1.display();
    s1.peek();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
}
