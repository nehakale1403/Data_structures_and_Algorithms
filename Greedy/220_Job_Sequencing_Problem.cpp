#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

static bool comp(job a, job b){
    return a.profit > b.profit;
}

vector<int> maxProfit(job arr[], int n){

    sort(arr, arr+n, comp);
    bool done[n] = {0};

    int day = 0, profit=0;
    for(int i=0; i<n; i++){
        for(int j=min(n, arr[i].deadline-1); j>=0; j--){
            if(done[j] == false){
                day+=1;
                profit += arr[i].profit;
                done[j] = true;
                break;
            }
        }
    }
    return {day, profit};
}

int main(){

    int n;
    cin>>n;
    struct job arr[n];

    for(int i=0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        arr[i].id = x;
        arr[i].deadline = y;
        arr[i].profit = z;
    }
    
    vector<int> ans = maxProfit(arr, n);
    cout<<ans[0]<<" -  "<<ans[1];
}