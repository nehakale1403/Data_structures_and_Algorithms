#include<bits/stdc++.h>
using namespace std;

bool findPow2(int n){

    if(n == 0) return false;

    int count=0;
    int rsbm = n & -n;

    while(n > 0){
        count++;
        n = n - rsbm;
        if(count > 1)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    cout<<findPow2(n);
}