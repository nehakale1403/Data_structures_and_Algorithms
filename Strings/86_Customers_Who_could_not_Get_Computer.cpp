#include<bits/stdc++.h>
using namespace std;

int solve(int n, string s){

    int len = s.length();

    int res=0;
    int occupied=0;
    unordered_map<char, int> map;

    
        

    for(int i=0; i<len; i++){
        char ch = s[i];
        cout<<"For character "<<ch<<":"<<endl;
        if(occupied < n){
            if(map.find(ch) == map.end()){
                cout<<"adding in map "<<endl;
                map[ch]++;
                occupied++;
                cout<<"Occupied: "<<occupied<<endl;
                cout<<endl;
            }else{
                cout<<"Erasing from the map"<<endl;
                map.erase(ch);
                occupied--;
                cout<<"Occupied: "<<occupied<<endl;
                cout<<endl;
            }
        }else if(occupied >= n){
            if(map.find(ch) != map.end()){
                cout<<"Erasing from the map"<<endl;
                map.erase(ch);
                occupied--;
                cout<<"Occupied: "<<occupied<<endl;
                cout<<endl;
            }else{
                cout<<"Updating the result"<<endl;
                cout<<endl;
                i++;
                res++;
            }
            
        }
        
    }
    return res;
}

int main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    cout<<solve(n, s);
    
}