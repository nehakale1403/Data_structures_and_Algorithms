#include<bits/stdc++.h>
using namespace std;

int divide(int a, int b){

    int res = 0;
    int dividend = abs(a);
    int divisor = abs(b);

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    while(dividend - divisor >= 0){
        int x = 0;
        while((dividend - (divisor << 1 << x)) >= 0){
            x++;
        }
        res += (1 << x);
        dividend -= (divisor << x);
    }
    return res;
}

int main(){
    int a, b;
    cin>>a>>b;

    cout<<divide(a, b);
}