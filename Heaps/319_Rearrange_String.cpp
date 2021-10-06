#include<bits/stdc++.h>
using namespace std;

struct key{

    int freq;
    char ch;

    bool operator<(const key& k) const{
        return freq < k.freq;
    }
};

string rearrange(string s){
    
    int n = s.length();

    int count[26] = {0};
    for(int i=0; i<n; i++){
        count[s[i] - 'a']++;
    }

    priority_queue<key> heap;

    for(char c = 'a'; c<='z'; c++){
        int val = c - 'a';
        if(count[val]){
            heap.push(key{count[val], c});
        }
    }

    s = "";

    key prev{-1, '#'};

    while(!heap.empty()){
        key k = heap.top();
        heap.pop();
        s = s + k.ch;

        if(prev.freq > 0)
            heap.push(prev);
        
        (k.freq)--;
        prev = k;
    }

    if(n!= s.length())
        return "";
    else
        return s;

}

int main(){

    string s;
    cin>>s;

    cout<<rearrange(s);
}