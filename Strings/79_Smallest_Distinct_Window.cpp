//here we are using sliding window

#include<bits/stdc++.h>
using namespace std;

int findSubStr(string s){

    unordered_map<char, int> m;
    set<char> st;
    for(int i=0; i<s.length(); i++)
        st.insert(s[i]);
    int n = st.size();
    int i=0, j=1;
    m[s[i]]++;
    int c=0;
    c++;
    int mi = INT_MAX;

    while(i<=j && j<s.length()){
        //expanding the window until we get all the characters
        if(c<n){
            if(m[s[j]]==0)
                c++;
            m[s[j]]++;
            j++;
        }else if(c==n){
            mi = min(mi, j-i);
            if(m[s[i]] == 1)
                c--;
            m[s[i]]--;
            i++;
        }
    }
    //shrinking
    while(c==n){
        mi = min(mi, j-i);
        if(m[s[i]] == 1)
            c--;
        m[s[i]]--;
        i++;
    }
    
    return mi;
}

int main(){
    
    string s;
    cin>>s;

    cout<<findSubStr(s);
}