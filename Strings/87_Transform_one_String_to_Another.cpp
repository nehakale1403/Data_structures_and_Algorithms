#include<bits/stdc++.h>
using namespace std;

int checkTransform(string a, string b){  

    int m = a.length();
    int n = b.length();

    if(m!=n)
        return -1;
    
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i=0; i<b.length(); i++)   
       count[b[i]]++;
    for (int i=0; i<a.length(); i++)   
       count[a[i]]--;         
    for (int i=0; i<256; i++)   
      if (count[i])
         return -1;

    int res=0;
    for(int i=n-1, j=n-1; i>=0; ){

        while(i>=0 && a[i] != b[j]){
            i--;
            res++;
        }

        if(i>=0){
            i--;
            j--;
        }
    }
    return res;

}

int main(){
    
    string a, b;
    cin>>a>>b;

    cout<<checkTransform(a, b);
}