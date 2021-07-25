#include<bits/stdc++.h>
using namespace std;

class mystack{
    int capacity;
    int top;
    int st[1000];

    public:
        mystack(int a){
            capacity = a;
            top = -1;
        }

        void push(int val){
            // cout<<"size 1 "<<isEmpty()<<endl;
            if(isFull()){
                cout<<"Overflow"<<endl;
                return;
            }

            st[++top] = val;
            // for(int i=0; i<capacity; i++){
            //     cout<<"Print "<<st[i]<<endl;
            // }
            // cout<<"size 2 "<<isEmpty()<<endl;
            return;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            
            return st[top--];
        }

        int peek(){
            if(!isEmpty()){
                return st[top];
            }else{
                return -1;
            }
        }

        int size(){
            return top+1;
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }

        bool isFull(){
            if(top == capacity-1)
                return true;
            else
                return false;
        }

};


int main(){

    int n;
    cout<<"Enter the size: ";
    cin>>n;

    mystack s(n);

    while(1){

        cout<<" 1. push \n 2. pop \n 3. peek \n 4. size \n 5. isempty \n 6. isfull \n 7. exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
            case 1:{
                cout<<"enter element: ";
                int ele;
                cin>>ele;
                s.push(ele);
                break;
            }

            case 2:{
                cout<<s.pop()<<endl;
                break;
            }

            case 3:{
                cout<<s.peek()<<endl;
                break;
            }

            case 4:{
                cout<<s.size()<<endl;
                break;
            }

            case 5:{
                cout<<s.isEmpty()<<endl;
                break;
            }

            case 6:{
                cout<<s.isFull()<<endl;
                break;
            }

            case 7:
                exit(EXIT_FAILURE);
        
        }
    
    }
}