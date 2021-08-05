#include<bits/stdc++.h>
using namespace std;

class Stack{

    int n;
    queue<int> q1;
    queue<int> q2;
    public:
        Stack(){
            n=0;
        }

        void push(int val){
            q2.push(val);
            n++;
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            //swapping the queues q1<->q2
            queue<int> temp;
            temp = q1;
            q1 = q2;
            q2 = temp;
        }

        void pop(){
            if (q1.empty())
                return;
            q1.pop();
            n--;
        }

        int top(){
            return q1.front();
        }

        int size(){
            return n;
        }
};

int main(){
    
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top();
}