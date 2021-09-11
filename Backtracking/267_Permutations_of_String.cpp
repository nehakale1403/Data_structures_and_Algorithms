#include<bits/stdc++.h>
using namespace std;

void findPerm(string s, int start, int end, vector<string> &v){
    if(start == end){
        v.push_back(s);
    }else{
        for(int i= start; i<= end; i++){
            swap(s[i], s[start]);
            findPerm(s, start+1, end, v);
        }
    }
}

vector<string> printPermutations(string s){

    int n = s.length();
    sort(s.begin(), s.end());
    vector<string> v;
    findPerm(s, 0, n-1, v);
    
}

int main(){
    string s;
    cin>>s;

    vector<string> res = printPermutations(s);
}