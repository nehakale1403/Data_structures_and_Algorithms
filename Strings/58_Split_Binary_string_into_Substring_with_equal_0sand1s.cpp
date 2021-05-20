#include<bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cin>>s;

    int count0=0, count1=0;
    int final_count=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='0'){
            count0++;
        }else if(s[i]=='1'){
            count1++;
        }

        if(count0==count1){
            final_count++;
            count0=count1=0;
        }
    }

    cout<<final_count;
}