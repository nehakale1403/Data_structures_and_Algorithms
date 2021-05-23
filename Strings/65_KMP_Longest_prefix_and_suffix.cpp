//Knuth Morris Pratt (KMP) is an algorithm, which checks the characters from left to right. 
// When a pattern has a sub-pattern appears more than one in the sub-pattern, 
// it uses that property to improve the time complexity, also for in the worst case.
// The time complexity of KMP is O(n).

#include<bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s){
    int n = s.length();

    int lps[n];
    lps[0] = 0;

    int len=0;

    int i=1;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n-1];
    
}
int main(){
    string s;
    cin>>s;
    cout<<longestPrefixSuffix(s);
}