#include<bits/stdc++.h>
using namespace std;
 
vector<int> inTime;
vector<int> outTime;
int timer = 1;
 
void resize(int n){
    inTime.resize(n+1);
    outTime.resize(n+1);
}
 
void dfs(int src,int par,vector<int> g[]){
    inTime[src] = timer++;
    for(auto x:g[src]){
        if(x!=par){
            dfs(x,src,g);
        }
    }
    outTime[src] = timer++;
}
 
bool check(int x,int y){
    if(inTime[x]>inTime[y] and outTime[x]<outTime[y]) 
        return true;
    return false;
}
  
int32_t main() {
 
    int n;
    cin>>n;
    timer = 1;
    resize(n);
    vector<int> g[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,g);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,x,y;
        cin>>type>>x>>y;
        if(!check(x,y) and !check(y,x)){
            cout<<"NO\n";
            continue;
        }
        if(type==0){
            if(check(y,x))
                cout<<"YES\n";
            else 
                cout<<"NO\n";
        }
        else if(type==1){
            if(check(x,y))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
 
    }
    return 0;
}






























// #include <bits/stdc++.h>
// using namespace std;

// bool canFind(int n, vector<int> adj[], int towards, int dst, int src){
//     // cout<<"here"<<endl;
//     if(src == dst) {
//         // cout<<"returning";
//         return true;
//     }
//     queue<int> q;
//     bool vis[n+1]= {0};
//     vis[src] = true;
//     q.push(src);
//     while(!q.empty()){
        
//         cout<<"next!"<<endl;
//         int node = q.front();
//         cout<<"Popping "<<q.front()<<endl;
//         q.pop();
//         if(node == dst){
//             cout<<"Reached!"<<endl;
//             return true;
//         }
//         if(node == 1 && towards==0) {
//             cout<<"i am here"<<endl;
//             return false;
//         }
//         if(towards == 1 && adj[node].size() == 1){
//             cout<<"hello"<<endl;
//             return false;
//         } 
//         for(auto it:adj[node]){
            
//             if(!vis[it]){
//                 cout<<"Pushing "<<it<<endl;
//                 if(it == dst) return true;
//                 q.push(it);
//                 vis[it] = true;
//             }
                
//         }
            
//     }
//     return false;
// }

// int main(){
//     int n;//total houses
//     cin>>n;
//     vector<int> adj[n+1];
//     for(int i=1; i<n; i++){
//         // cout<<"here"<<endl;
//         int x, y;
//         cin>>x>>y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int towards, dst, src;
//         cin>>towards>>dst>>src;
//         cout<<canFind(n, adj, towards, dst, src)<<endl;
//     }

// }