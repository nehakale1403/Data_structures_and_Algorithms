#include<bits/stdc++.h>
using namespace std;

class circularQueue{

    int *arr;
    int size;

    int front, rear;

    public:
        circularQueue(int n){
            size = n;
            arr = new int[n];

            front = rear = -1;
        }

        bool isFull(){
            if((front == 0 && rear == size-1) || ((rear == front-1)%(size-1)))
                return true;
            else
                return false;


        }

        bool isEmpty(){
            if(front == -1)
                return true;
            else
                return false;
        }

        void enqueue(int ele){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }else if(front == -1){
                front = rear = 0;
                arr[front] = ele;
            }else{
                rear = (rear+1)%size;
                arr[rear] = ele;
            }
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return INT_MIN;
            }

            int data = arr[front];
            arr[front] = -1;
            if(front == rear){
                front = rear = -1;
            }else{
                front = (front+1)%size;
            }
            return data;
        }
};

int main(){
    circularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl;
    q.enqueue(5);
    cout<<q.dequeue();
}