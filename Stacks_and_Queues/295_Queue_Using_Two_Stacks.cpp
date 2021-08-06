#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    int n;
    public:
        Queue(){
            n=0;
        }

        void push(int ele){
            n++;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(ele);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void pop(){
            if(s1.empty())
                return;
            s1.pop();
            n--;
        }

        int front(){
            return s1.top();
        }
};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.pop();
    cout<<q.front();
}