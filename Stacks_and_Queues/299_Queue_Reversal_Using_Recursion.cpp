#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q){

    if(q.empty())
        return;
    
    int data = q.front();
    q.pop();

    reverseQueue(q);

    q.push(data);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    reverseQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
        
}