#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a, b, c;
    cin>>a>>b>>c;

    if(a>b){
        if(b>c)
            cout<<b;
        else if(a>c)
            cout<<c;
        else
            cout<<a;
    }else{
        //here a is not greater than b
        if(a>c)
            cout<<a;
        else if(c>b)
            cout<<b;
        else
            cout<<c;
    }
}