#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int max_overall = arr[0];
    int max_till_here = arr[0];
    int min_till_here = arr[0];

    for(int i=1; i<n; i++){
        int temp = max_till_here;
        max_till_here = max({arr[i]*max_till_here, arr[i]*min_till_here, arr[i]});
        min_till_here = min({arr[i]*temp, arr[i]*min_till_here, arr[i]});
        max_overall = max(max_overall, max_till_here);

    }

    cout<<max_overall;

}