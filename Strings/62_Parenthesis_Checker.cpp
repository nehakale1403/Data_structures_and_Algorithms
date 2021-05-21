#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin>>s;

    stack<char> st;
    int flag = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if(st.empty()){
            flag = 1;
            break;
        }
        else if((s[i] =='}' || s[i] == ']' || s[i] == ')')){

            if((s[i]=='}' && st.top() == '{') || (s[i]==')' && st.top() == '(')|| (s[i]==']' && st.top() == '['))
                st.pop();
            else{
                flag = 1;
                break;
            }
        }
            
    }

    if(flag == 1 || !st.empty()){
        cout<<"NO";
    }else{
        cout<<"YES";
    }

}