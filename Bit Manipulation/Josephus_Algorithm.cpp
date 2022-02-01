#include <bits/stdc++.h>
using namespace std;

//killing all the alternate soldiers, tell at the end which one is alive

int powerof2(int n){
    int i = 1;
    while(i*2 <= n){
        i *= 2;
    }
    return i;
}

int solution(int n){
    int hp2 = powerof2(n);
    int l = n - hp2;
    return 2 * l + 1;
}

int main(){
    int n;
    cin>>n;

    cout<<solution(n);
}