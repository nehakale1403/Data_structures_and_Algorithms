#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 26

int minStringValue(string s, int k){
    int l = s.length();

    if(k>=l)
        return 0;
    
    int frequency[MAX_CHAR] = {0};
    for(int i=0; i<l; i++)
        frequency[s[i] - 'a']++;
    
    priority_queue<int> q;
    for(int i=0; i<MAX_CHAR; i++)
        q.push(frequency[i]);
    
    while(k--){
        int temp = q.top();
        q.pop();
        temp = temp-1;
        q.push(temp);
    }

    int res = 0;
    while(!q.empty()){
        int temp = q.top();
        res += temp*temp;
        q.pop();
    }

    return res;
}

int main(){
    string s;
    cin>>s;

    int k;
    cin>>k;
    
    cout<<minStringValue(s, k);
}