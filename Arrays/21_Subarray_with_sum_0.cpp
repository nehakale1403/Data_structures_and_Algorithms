#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    
    int sum = 0;
    int flag = 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        sum = sum+arr[i];
        if(sum == 0 or arr[i] == 0 or m[sum]){ //m[s] means the sum number already exists  in the map
            flag=1;
            break;
        }else{
            m[sum]++;
        }
    }
    if(flag==1)
        cout<<"Yes";
    else
        cout<<"No";
}