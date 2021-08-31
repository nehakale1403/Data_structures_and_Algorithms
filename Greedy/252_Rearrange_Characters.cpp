#include<bits/stdc++.h>
using namespace std;

bool solve(string s){

    int n = s.length();

    unordered_map<char, int> mp;
    for(int i=0;i<n; i++){
        mp[s[i]]++;

        if(mp[s[i]] > n/2){
            return 0;
        }
    }
    return 1;
}

int main(){
    
    string s;
    cin>>s;

    cout<<solve(s);
}