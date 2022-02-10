#include<bits/stdc++.h>
using namespace std;

int powerIndex(int n){
    int x = 0;

    while((1 << x) <= n){
        x++;
    }
    return x;
}

int findPos(int n){

    if(n == 0) return -1;

    int count=0;
    int rsbm = n & -n;

    while(n > 0){
        count++;
        n = n - rsbm;
        if(count > 1)
            return -1;
    }
    
    
    return powerIndex(rsbm);
}

int main(){
    int n;
    cin>>n;

    cout<<findPos(n);
}