#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int c1=0, c2=0;
    for(int i=0; i<s.length(); i++){

        if((i%2 == 1) && s[i] == '1') c1++;
        if((i%2 == 0) && s[i] == '0') c1++;
        if((i%2 == 1) && s[i] == '0') c2++;
        if((i%2 == 0) && s[i] == '1') c2++;
    }

    cout<<min(c1, c2);
}