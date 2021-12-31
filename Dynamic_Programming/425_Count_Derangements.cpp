#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int countDerangements(int n){

    if(n == 1) return 0;
    if(n == 2) return 1;

    if(memo.find(n) != memo.end()) return memo[n];

    return memo[n] = (n-1) * (countDerangements(n-1) + countDerangements(n-2));
}

int main(){

    int n;
    cin>>n;

    cout<<countDerangements(n);
}