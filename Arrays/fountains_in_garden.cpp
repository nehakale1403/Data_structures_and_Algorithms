#include<bits/stdc++.h>
using namespace std;

int minCount(int arr[], int n){

    vector<pair<int, int>> ranges(n);
    for(int i=0; i<n; i++){
        ranges[i].first = i - arr[i];
        ranges[i].second = i + arr[i];
    }

    int minimum = 0;
    int maximum = 0;

    int funCount=0;
    while(maximum < n-1){
        for(int i=minimum; i<n; i++){
    
            if(ranges[i].first <= minimum && ranges[i].second > maximum){
                maximum  = ranges[i].second;
                // cout<<maximum<<endl;
            }          
        }
        if(minimum == maximum) return -1;
        funCount++;
        minimum = maximum;
    }
    return funCount;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<minCount(arr, n);
}