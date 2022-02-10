#include<bits/stdc++.h>
using namespace std;

vector<string> powerSet(string s){

    vector<string> res;

    string substr = "";

    for(int i=0; i < (1 << s.length()); i++){
        //001
        for(int j=0; j<s.length(); j++){
            if(i & (1 << j)){
                substr += s[j];
            }
        }
        if(substr != "")
            res.push_back(substr);
        substr = "";
    }

    sort(res.begin(), res.end());
    return res;
}

int main(){
    
    string s;
    cin>>s;

    vector<string> res = powerSet(s);

    for(auto it: res){
        cout<<it<<endl;
    }
}