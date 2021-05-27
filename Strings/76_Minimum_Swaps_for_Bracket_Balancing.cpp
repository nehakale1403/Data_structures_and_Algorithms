#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int ans=0;
    int open=0, close=0;
    int fault=0;
    for(int i=0; i<=s.length(); i++){
        if(s[i] == ']'){
            close++;
            fault = close-open;
        }else{
            open++;
            if(fault>0){
                ans+=fault;
                fault--;
            }
        }
    }
    
    cout<<ans;
}