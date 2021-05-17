#include<bits/stdc++.h>
using namespace std;

int main(){

    string str;
    cin>>str;

    map<char, int> count;
    for(int i=0; i<str.length(); i++){
        count[str[i]]++;
    }

    for(auto i:count){
        if(i.second > 1)
            cout<<i.first<<" count= "<<i.second<<endl;
    }

}