#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)

static bool compare(pii p1, pii p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1>v2;
}


int main(){
    
    int n;
    cin>>n;
    
    vii a(n);

    rep(i, 0, n){
        cin>>a[i].first>>a[i].second;
    }
    
    //knapsack capacity
    int k;
    cin>>k;
    sort(a.begin(), a.end(), compare);

    double ans=0;

    rep(i, 0, n){

        if(k>=a[i].second){
            ans += a[i].first;
            k -= a[i].second;
            continue;
        }
        double vw = (double) a[i].first/a[i].second; //value per weight 
        ans += vw * k;
        k=0;
        break;
    }

    cout<<ans<<endl;
}