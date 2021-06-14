#include<bits/stdc++.h>
using namespace std;

int main(){

    int p,q,s,n;
    cin>>p>>q>>s>>n;

    map<int, int> v;

    v.push_back(0,0);
    v.push_back(0,q);
    v.push_back(p,0);
    if(q>p)
        v.push_back(p, q-p);
    else
        v.push_back(p-q, q);
    v.push_back(p,q);

    int ans=0;
    int t=0;
    while(s--){

        for(int i=0; i<v.size(); i++){
            t = min(t, n-v[i]);
        }
        
    }
}