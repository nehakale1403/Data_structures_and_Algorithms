#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
int jobScheduling(vector<int> startTime,vector<int> endTime, vector<int> profit, int n){

    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        int x = startTime[i];
        int y = endTime[i];
        int z = profit[i];
        v[i] = {x,y,z};
    }
    sort(v.begin(), v.end(), comp);
    int dp[n];
    //dp[0] is the profit at index 0
    dp[0] = v[0][2];

    for(int i=1; i<n;i++){
        //including the profit at index i
        int inc = v[i][2];
        int last= -1;
        int low=0;
        int high = i-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(v[mid][1]<=v[i][0]){
                last = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(last!=-1)
            inc += dp[last];
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
    }
    return dp[n-1];
}

int main(){
    
    int n;
    cin>>n;

    vector<int> startTime(n);
    vector<int> endTime(n);
    vector<int> profit(n);

    for(int i=0; i<n; i++)
        cin>>startTime[i];

    for(int i=0; i<n; i++)
        cin>>endTime[i];

    for(int i=0; i<n; i++)
        cin>>profit[i];
    
    cout<<jobScheduling(startTime, endTime, profit, n);
}