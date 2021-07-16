#include<bits/stdc++.h>
using namespace std;


int main(){
    
    string s;
    cin>>s;

    int l, r;
    cin>>l>>r;

    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1'){
            for(int j=i; j<s.length(); j++){
                string bs = s.substr(i, j+1);
                if(bs.length()>32)
                    break;
                int num = stoi(bs);
                if(num>=l && num<=r)
                    count++;
            }
        }
    }

    cout<<count<<endl;
    
}