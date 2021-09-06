#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int l = 0;
    int r = str.length()-1;

    while(l<r){
        if(str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void palindromePartition(string s, string asf){

    if(s.length() == 0){
        cout<<asf<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++){
        string prefix = s.substr(0, i+1);
        string rest = s.substr(i+1);
        if(isPalindrome(prefix)){
            palindromePartition(rest, asf + "(" + prefix + ")");
        }
    }
}

int main(){
    string s;
    cin>>s;

    palindromePartition(s, "");
}