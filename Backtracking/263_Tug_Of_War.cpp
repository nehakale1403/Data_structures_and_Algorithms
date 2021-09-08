#include<bits/stdc++.h>
using namespace std;

static int mindiff = INT_MAX;
vector<int> ans;


void solve(int arr[], int n, int vidx, vector<int> set1, vector<int> set2, int sums1, int sums2){

    if(vidx == n){
        int delta = abs(sums1-sums2);
        if(delta<mindiff){
            mindiff = delta;
            ans.clear();
            for(int i=0; i<set1.size(); i++){
                ans.push_back(set1[i]);
            }
            ans.push_back(000);
            for(int i=0; i<set2.size(); i++){
                ans.push_back(set2[i]);
            }
        }
        return;
    }
    if(set1.size() < (n+1)/2){
        set1.push_back(arr[vidx]);
        solve(arr,n, vidx+1, set1, set2, sums1 + arr[vidx], sums2);
        set1.pop_back();
    }
    
    if(set2.size() < (n+1)/2){
        set2.push_back(arr[vidx]);
        solve(arr,n, vidx+1, set1, set2, sums1, sums2 + arr[vidx]);
        set2.pop_back();
    }
    
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> set1, set2;
    solve(arr, n,0, set1, set2, 0, 0);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}