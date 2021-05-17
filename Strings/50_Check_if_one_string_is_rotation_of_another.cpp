#include<bits/stdc++.h>
using namespace std;

bool checkrotation(string s1, string s2){
    if(s1.length()!=s2.length())
        return 0;

    string temp=s1+s1;

    if(temp.find(s2) != string::npos){
        return true;
    } else {
        return false;
   }
}

int main(){

    string str1, str2;

    cin>>str1>>str2;

    cout<<checkrotation(str1, str2);
    
}