#include<bits/stdc++.h>
using namespace std;

vector<int> minAndMaxAmt(int arr[], int n, int k){

    sort(arr, arr+n);
    int i=0, j=n-1;
    int min=0, max=0;
    while(i<=j){
        min += arr[i];
        j -= k;
        i++;
    }

    i=0, j=n-1;
    while(i<=j){
        max += arr[j];
        i += k;
        j--;
    }
    
    vector<int> v;
    v.push_back(min);
    v.push_back(max);
    return v;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    vector<int> v = minAndMaxAmt(arr, n, k);
    cout<<v[0]<<" "<<v[1];
}   