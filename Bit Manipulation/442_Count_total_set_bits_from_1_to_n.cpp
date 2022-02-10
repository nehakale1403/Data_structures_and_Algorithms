#include<bits/stdc++.h>
using namespace std;

int largestPowerOf2InRange(int n){
    int x = 0;

    while((1 << x) <= n){
        x++;
    }

    return x-1;
}

int countSetBits(int n){

    if(n < 1) return 0;

    int x = largestPowerOf2InRange(n);

    int bitsUpto2raisex = x * (1 << (x-1));
    int msbfor2rxton = n - (1 << x) + 1;

    return bitsUpto2raisex + msbfor2rxton + countSetBits(n- (1 << x));
}


int main(){
    int n;
    cin>>n;

    cout<<countSetBits(n);
}