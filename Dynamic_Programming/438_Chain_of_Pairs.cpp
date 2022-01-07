#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};


int comp(struct val a , struct val b) {
return (a.first < b.first);
}

int findLongestChain(struct val p[], int n){

    if(n <= 1) return n;

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

    struct val p[n];
    for(int i=0; i<n; i++){
        cin>>p->first>>p->second;
    }

    cout<<findLongestChain(p, n);
}