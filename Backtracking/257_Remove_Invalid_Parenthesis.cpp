#include<bits/stdc++.h>
using namespace std;

int getMinimum(string s){

    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            if(st.empty()){
                st.push(ch);
            }else if(st.top() == ')'){
                st.push(ch);
            }else if(st.top() == '('){
                st.pop();
            }
        }
    }

    return st.size();
}


void solution(string s, int min_removal, vector<string> &v){

    if(min_removal == 0){
        int mrnow = getMinimum(s);
        if(mrnow == 0){
            if(find(v.begin(), v.end(), s) == v.end())
                cout<<s<<endl;
            v.push_back(s);
        }
        return;
    }
    for(int i=0; i<s.length(); i++){
        string left = s.substr(0, i);
        string right = s.substr(i+1);
        solution(left+right, min_removal-1, v);
    }
}


int main(){
    
    string s;
    cin>>s;

    int min_removal = getMinimum(s);

    vector<string> v;
    solution(s, min_removal, v);
}