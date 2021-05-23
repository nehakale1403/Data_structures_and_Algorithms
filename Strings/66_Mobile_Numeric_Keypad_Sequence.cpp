#include<bits/stdc++.h>
using namespace std;

string printSeq(string arr[], string s){

    string output = "";
    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            output = output+ "0";
        }else{
            int position = s[i] - 'A'; //it takes ascii value for s[i] and A
            output = output + arr[position];
        }
    }
    return output;
}


int main(){

    string s;
    cin>>s;
    
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777","7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};
    
    cout<<printSeq(str, s);
}