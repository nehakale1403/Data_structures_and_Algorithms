#include<bits/stdc++.h>
using namespace std;


static string maxs;

void findMaximum(string s,int k){

    if(k==0)
        return;

    for(int i=0; i<s.length()-1; i++){
        for(int j=i+1; j<s.length(); j++){
            if(s[j] > s[i]){
                swap(s[i], s[j]);
                
                if(s.compare(maxs) > 0)
                    maxs = s;
                
                findMaximum(s, k-1);

                swap(s[i], s[j]);
            }
        }
    }
}



int main(){ 
    string s;
    cin>>s;

    int k;
    cin>>k;

    findMaximum(s, k);

    cout<<maxs;
}