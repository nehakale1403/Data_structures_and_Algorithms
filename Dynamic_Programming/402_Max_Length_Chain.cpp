#include<bits/stdc++.h>
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int maxChainLen(pair<int, int> p[], int n){

    if(n == 0 || n == 1) return n;

    sort(&p[0], &p[n], comp);

    int dp[n+1] = {0};
    int m = 0;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(p[i].first > p[j].second){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        m = max(dp[i], m);
    }

    return m;
}

int main(){
    
    int n;
    cin>>n;

    pair<int, int> p[n];

    for(int i=0; i<n; i++){
        cin>>p[i].first>>p[i].second;
    }

    cout<<maxChainLen(p, n);
}