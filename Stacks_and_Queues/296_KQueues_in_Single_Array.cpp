#include<bits/stdc++.h>
using namespace std;

class kQueues{

    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int free;

    public:
        kQueues(int k1, int n1){
            k = k1;
            n = n1;

            arr = new int[n];
            front = new int[k];
            rear  = new int[k];
            next = new int[n];

            for(int i=0; i<k; i++){
                front[i] = -1;
            }

            free = 0;
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        bool isFull()   {  return (free == -1);  }

        bool isEmpty(int qn)  {  return (front[qn] == -1); }

        void enqueue(int ele, int qn){
            if(isFull())
                cout<<"Queue Overflow"<<endl;
            
            int i=free;
            free = next[i];
            if(isEmpty(qn))
                front[qn] = i;
            else
                next[rear[qn]] = i;
            
            next[i] = -1;
            rear[qn] = i;
            arr[i] = ele;
        }

        int dequeue(int qn){
            if(isEmpty(qn)){
                cout<<"Queue Underflow"<<endl;
                return INT_MAX;
            }

            int i=front[qn];
            front[qn] = next[i];
            next[i] = free;
            free = i;

            return arr[i];
        }

};

int main(){
    int k=3, n=10;

    kQueues kq(k, n);

    kq.enqueue(11, 1);
    kq.enqueue(12, 2);
    kq.enqueue(13, 2);

    cout<<kq.dequeue(2)<<endl;
    cout<<kq.dequeue(1)<<endl;
    cout<<kq.isEmpty(1);
}