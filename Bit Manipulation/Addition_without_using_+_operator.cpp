#include<bits/stdc++.h>
using namespace std;

int add(int a, int b){

    int xorr = a ^ b;
    int carry = a & b;
    if(carry == 0)
        return xorr;
    else
        return add(xorr, carry << 1);

}

int main(){
    int a, b;
    cin>>a>>b;

    cout<<add(a, b);
}