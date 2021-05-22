#include<bits/stdc++.h>
using namespace std;

#define d 256

void search(string pat, string txt, int q){
    int m = pat.length();
    int n = txt.length();

    int i, j;
    int p=0; //hash value for pattern
    int t=0; //hash value for text
    int h=1;

    // The value of h would be "pow(d, M-1)%q" 
    for(int i=0; i<m-1; i++){
        h = (h*d) % q;
    }

    // Calculate the hash value of pattern and first 
	// window of text 
    for(int i=0; i<m; i++){

        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;

    }

    //Sliding the pattern over text one by one
    for(i=0; i<=n-m; i++){

        if(p==t){
            for(j=0; j<m; j++){
                if(txt[i+j] != pat[j])
                    break;
            }

            if(j == m)
                cout<<"Pattern found at index "<<i<<endl;
        }

        if(i< n-m){
            t = (d*(t- txt[i]*h) + txt[i+m]) %q;

            if(t<0)
                t = t+q;
        }
    }

}

int main(){

    string text, pattern;
    cin>>text>>pattern;

    int q = 101;
    search(pattern, text, q);
    return 0;
}
