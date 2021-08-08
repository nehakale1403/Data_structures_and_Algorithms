#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    list<int> dq;
    unordered_map<int, list<int>::iterator> mp;
    int csize;

    public:
        //constructor
        LRUCache(int n){
            csize = n;
        }

        //
        void refer(int x){

            if(mp.find(x) == mp.end()){
                if(dq.size() == csize){
                    int last = dq.back();
                    dq.pop_back();
                    mp.erase(last);
                }
            }else{
                dq.erase(mp[x]);
            }

            dq.push_front(x);
            mp[x] = dq.begin();
        }

        void display(){
            for(auto it = dq.begin(); it != dq.end(); it++){
                cout<<(*it)<<" ";
            }
            cout<<endl;
        }
};

int main(){

    LRUCache ca(4);
 
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
 
    return 0;
    
}