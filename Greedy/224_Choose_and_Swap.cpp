#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string s){

    set<char> st;
    for(int i=0; i<s.length(); i++)
        st.insert(s[i]);
    
    for(int i=0; i<s.length(); i++){
        st.erase(s[i]);
        if(st.empty()) break;
        char ch = *st.begin();
        if(ch< s[i]){
        
            int ch2 = s[i];
            for(int j=0; j<s.length(); j++){
                if(s[j] == ch) s[j] = ch2;
                else if(s[j] == ch2) s[j] = ch;
            }
            break;
        }
    }
    return s;
}

int main(){
    
    string s;
    cin>>s;

    string ans  = chooseandswap(s);
    cout<<ans;
}