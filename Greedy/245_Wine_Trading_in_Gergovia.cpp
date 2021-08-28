#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    vector<pair<int, int>> buy;
    vector<pair<int, int>> sell;

    for(int i=0; i<n; i++){
        if(a[i]<0){
            sell.push_back({a[i], i});
        }else{
            buy.push_back({a[i], i});
        }
    }

    int energy=0;
    int i=0, j=0;

    while(i<buy.size() && j<sell.size()){
        int x = min(buy[i].first, -sell[j].first);
        buy[i].first -= x;
        sell[j].first += x;

        int diff = abs(buy[i].second - sell[j].second);
        energy += (x*diff);
        if(buy[i].first == 0) i++;
        if(sell[j].first == 0) j++;
    }

    cout<<energy<<endl;
}