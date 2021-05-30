//naive approach...deleting the last element until we get the palindrome----O(n^2)
//todo the question with KMP algo
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){

    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;      
    }
    return true;
}

int minChar(string s){

    int n = s.length();

    int i=0;
    int j=n-1;

    while(!(isPalindrome(s, i, j))){
        j--;
    }
    int count = n-j-1;
    return count;
}
int main(){
    string s;
    cin>>s;
    
    cout<<minChar(s);
}