#include<bits/stdc++.h>
using namespace std;

int computenPr(int n, int r){
    int p = 1;
    for(int i=0; i<r; i++){
        p = p * (n-i);
    }
    return p;
}

int main(){

    int n, r;
    cin>>n>>r;

    cout<<computenPr(n, r);
}