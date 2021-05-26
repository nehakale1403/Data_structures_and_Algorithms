#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    unordered_map<string, int> map;

    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    int max=0, sec_max=0;
    string ans;
    for(auto i: map){
        if(max<i.second){
            sec_max = max;
            max = i.second;
            cout<<max<<" "<<sec_max<<endl;
        }else if(i.second > sec_max && i.second!=max){
            sec_max = i.second;
        }
    }

    for(auto i: map){
        if(i.second == sec_max)
            cout<<i.first;
    }
    
}