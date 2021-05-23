#include<bits/stdc++.h>
using namespace std;

int countRev(string s){

    int n = s.length();

    if(n%2 == 1)
        return -1;

    stack<char> st;
    int c=0; //closing
    int c2=0; //opening
    for(int i=0; i<n; i++){
        
        if(s[i] == '{'){
            st.push(s[i]);
            c2++;
        }else if(s[i] == '}' && !st.empty() && st.top() == '{'){
            st.pop();
            c2--;
        }else{
            c++;
        } 
    }

    if(c&1)
        c = (c/2) + 1;
    else
        c = c/2;

    if(c2&1)
        c2 = (c2/2) + 1;
    else
        c2 = c2/2;


    return(c+c2);
}

int main(){

    string s;
    cin>>s;

    cout<<countRev(s);
}