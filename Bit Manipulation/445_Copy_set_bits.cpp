#include<bits/stdc++.h>
using namespace std;

unsigned copySetBits(unsigned x, unsigned y, unsigned l, unsigned r){

    if(l < 1 || r > 32)
        return x;

    for(int i = l; i<=r; i++){
        int mask = (1 << (i-1));

        if(y & mask)
            x = x | mask;
    }
    return x;    
}

int main(){

    int x, y, l, r;
    cin>>x>>y>>l>>r;

    cout<<copySetBits(x, y, l, r);
}