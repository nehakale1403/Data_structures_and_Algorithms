#include<bits/stdc++.h>
using namespace std;

class myqueue{

    int capacity;
    int q[100];
    int front;
    int rear;
    int size;

    public:
        myqueue(int s){
            capacity = s;
            int front = -1;
            int rear = -1;
            size = 0;
        }

        void enqueue(int val){
            if(isFull())
                cout<<"Queue is Full"<<endl;
            else{
                if(size==0){            
                    front=0;
                    rear=0;
                    q[rear] = val;
                    size++;
                }else{
                    rear= (rear+1)%capacity;
                    q[rear] = val;
                    size++;
                }
                
            }
        }

        int dequeue(){
            if(isEmpty())
                cout<<"Queue is empty"<<endl;
            else{
                if(size == 1){
                    rear = -1;
                    front = -1;
                    size--;
                }else{
                    front = (front+1)%capacity;
                    size--;
                }
                
            }
        }

        bool isFull(){
            if(size == capacity-1)
                return true;
            else
                return false;
        }

        bool isEmpty(){
            if(size == 0)
                return true;
            return false;
        }

        int frontEle(){
            return q[front];
        }

        int rearEle(){
            return q[rear];
        }
};

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    myqueue que(n);

    while(1){

        cout<<" 1. enqueue \n 2. dequeue \n 3. isfull \n 4. isempty \n 5. front \n 6. rear \n 7. exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:{
                cout<<"enter element: ";
                int ele;
                cin>>ele;
                que.enqueue(ele);
                break;
            }

            case 2:{
                cout<<que.dequeue()<<endl;
                break;
            }

            case 3:{
                cout<<que.isFull()<<endl;
                break;
            }

            case 4:{
                cout<<que.isEmpty()<<endl;
                break;
            }

            case 5:{
                cout<<que.frontEle()<<endl;
                break;
            }

            case 6:{
                cout<<que.rearEle()<<endl;
                break;
            }

            case 7:
                exit(EXIT_FAILURE);
        
        }
    
    }
}