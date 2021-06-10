#include<bits/stdc++.h>
using namespace std;

int minswaps(int arr[], int n){

    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++)
        v[i] = {arr[i], i};
    sort(v.begin(), v.end());
    int c=0;

    for(int i=0; i<n; i++){
        
        if(v[i].second == i)
            continue;
        else{
            c++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return c;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<minswaps(arr, n);
}