#include<bits/stdc++.h>
using namespace std;

class Stack{
    deque<int> dq;
    int n;

    public:
        Stack(){
            n=0;
        }
        void push(int val){
            dq.push_front(val);
            n++;
        }
        void pop(){
            if(dq.empty())
                return;
            dq.pop_front();
            n--;
        }
        int top(){
            return dq.front();
        }
        int size(){
            return n;
        }
};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size();
}