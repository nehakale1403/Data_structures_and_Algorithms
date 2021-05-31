#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int n = s.length();
    cout<<s[0];
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1])
            cout<<s[i];
    }
}