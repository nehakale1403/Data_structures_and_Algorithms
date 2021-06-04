#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n+1];
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    
    int miss, repeat;
    int temp[n+1] = {0};

    for(int i=1; i<=n; i++){
        temp[arr[i]]++;
    }

    for(int i=1; i<=n; i++){
        if(temp[i] == 0)
            miss = i;
        if(temp[i] == 2)
            repeat = i;
    }

    cout<<repeat<<" "<<miss;
}