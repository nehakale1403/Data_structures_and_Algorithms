// https://www.youtube.com/watch?v=4Oj_ESzSNCk&ab_channel=BharathiRameshBharathiRamesh

#include<bits/stdc++.h>
using namespace std;

# define NO_OF_CHARS 256

void badMatchTable(string str, int size, int badchar[NO_OF_CHARS]){
    int i;

    for(i=0; i<NO_OF_CHARS; i++){
        badchar[i] = -1;
    }

    for(i=0; i<size; i++){
        badchar[(int) str[i]] = i;
    }
}

void search(string txt, string pat){

    int n = txt.length();
    int m = pat.length();

    int badchar[NO_OF_CHARS];

    badMatchTable(pat, m, badchar);

    int s=0; //to shift the pattern

    while(s<=(n-m)){
        int j=m-1;

        while (j>=0 && pat[j] == txt[s+j])
            j--;
        
        if(j<0){
            cout<<"Pattern occurs at shift = "<<s<<endl;
            s+=(s+m<n) ? m-badchar[txt[s+m]] : 1;
        }else{
            s+=max(1, j-badchar[txt[s+j]]);
        }
        
    }
}

int main(){
    string text;
    cin>>text;

    string pattern;
    cin>>pattern;

    search(text, pattern);
}