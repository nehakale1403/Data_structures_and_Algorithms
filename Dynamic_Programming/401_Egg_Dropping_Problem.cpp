#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int criticalFloor(int n, int k){

    if(k == 1 || k == 0) return k;

    if(n == 1) return k;

    if(memo.find({n, k}) != memo.end()) return memo[{n, k}];

    int res, x,  minn = INT_MAX;

    for(x= 1; x<=k; x++){
        res = max(criticalFloor(n, k-x), criticalFloor(n-1, x-1));
        if(res < minn)
            minn = res;
    }
    return memo[{n, k}] = minn + 1;
}

int main(){
    int n, k;
    cin>>n>>k;

    cout<<criticalFloor(n, k);
}