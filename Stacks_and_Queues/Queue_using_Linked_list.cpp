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

class Queue{

    Node* front;
    Node* rear;
    int size;
    public:
        Queue(int a){
            front = NULL;
            rear = NULL;
            size=0;
        }

        void enqueue(int data){
            Node* temp = new Node(data);
            if(front == NULL){
                front = rear = temp;
            }else{
                rear->next = temp;
                rear = temp;
            }
        }
        
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
            }else if(front == rear){
                Node *p = front;
                delete(p);
                front = rear = NULL;
            }else{
                Node* p = front;
                front = front->next;
                delete(p);
            }   
        }

        bool isEmpty(){
            if(front == NULL)
                return true;
            return false;
        }

        void display(){
            Node *p = front;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            cout<<endl;
        }

        void sizeQ(){
            Node *p = front;
            int count=0;
            while(p != NULL){
                count++;
                p = p->next;
            }

            cout<<count<<endl;
        }

};


int main(){

    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.display();
    q1.sizeQ();
}
