#include<bits/stdc++.h>
using namespace std;

map<char, vector<char>> mp;

void findEmps(char manager){
    vector<char> vis;
    queue<char> q;

    for(auto it: mp){
        if(it.first == manager){
            for(auto i: it.second)
                q.push(i);
        }
    }

    while(!q.empty()){
        if(find (vis.begin(), vis.end(), q.front()) == vis.end()){

            vis.push_back(q.front());
            cout<<q.front();
            for(auto it: mp){
                if(it.first == q.front()){
                    for(auto i: it.second)
                        q.push(i);
                }
            }
            q.pop();
        }
    }
        
}

int main(){
    
    int employees, relations;
    cin>>employees>>relations;

    int v = employees;
    int e = relations;

    
    for(int i=0; i<e; i++){
        char emp, mang;
        cin>>emp>>mang;
        if(emp != mang)
            mp[mang].push_back(emp);
    }

    for(auto it: mp){
        cout<<it.first<<" -> ";
        for(int i=0; i<it.second.size(); i++){
            cout<<it.second[i]<<" ";
        }
        cout<<endl;
    }

    findEmps('a');
    cout<<endl;
    findEmps('b');
    cout<<endl;
    findEmps('c');
    cout<<endl;
    findEmps('d');
    cout<<endl;
    findEmps('e');
    cout<<endl;
    findEmps('f');
    
}




// 6 6
// a c
// b c
// c f
// d e
// e f
// f f