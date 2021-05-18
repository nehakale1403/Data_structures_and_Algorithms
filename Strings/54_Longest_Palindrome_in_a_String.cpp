#include<bits/stdc++.h>
using namespace std;

void printSubStr(string s, int low, int high){

    for(int i=low; i<=high; i++)
        cout<<s[i];

    cout<<endl;
}

int  longestPalSubstring(string s){

    int n = s.size();

    bool table[n][n];
    memset(table, 0, sizeof(table));

    int max_length=1;

    for(int i=0; i<n; i++)
        table[i][i]=true;
    
    int start=0;
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            table[i][i+1]=true;
            start=i;
            max_length=2;
        }
    }

    for(int k=3; k<=n; k++){
        for(int i=0; i< n-k+1; i++){
            int j=i+k-1;
            if(table[i+1][j-1] && s[i] == s[j]){
                table[i][j]=true;
                if(k>max_length){
                    start=i;
                    max_length=k;
                }
            }
        }
    }
    printSubStr(s, start, start + max_length - 1);

    return max_length;
}
int main(){

    string s;
    cin>>s;

    cout<<longestPalSubstring(s);
    
}