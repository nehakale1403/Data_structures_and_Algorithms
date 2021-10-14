#include<bits/stdc++.h>
using namespace std;

int ladderLength(string start, string end, vector<string> &wordlist){
    queue<string> q;
    q.push(start);
    int wordsize = start.size();

    unordered_set<string> sett;
    for(int i=0; i<wordlist.size(); i++){
        sett.insert(wordlist[i]);
    }

    if(sett.find(end) == sett.end()) return 0;
    int len = 0;
    while(!q.empty()){
        len++;
        int qlen = q.size();
        for(int i=0; i<qlen; i++){
            string s = q.front();
            q.pop();
            for(int j=0; j<wordsize; j++){
                char org = s[j];
                for(char ch = 'a'; ch<='z'; ch++){
                    s[j] = ch;
                    if(s == end) return len+1;
                    if(sett.find(s) == sett.end()) continue;

                    sett.erase(s);
                    q.push(s);
                }
                s[j] = org;
            }
        }
    }
    return 0;
}

int main(){

    string start, end;
    cin>>start>>end;
    
    int n;
    cin>>n;
    vector<string> wordlist(n);

    for(int i=0; i<n; i++){
        cin>>wordlist[i];
    }

    cout<<ladderLength(start, end, wordlist);
}