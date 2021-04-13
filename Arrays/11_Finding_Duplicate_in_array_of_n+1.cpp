// https://www.youtube.com/watch?v=kV37sZV9pgk&ab_channel=CodeLibrary

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++){
        arr[arr[i]%n] += n;
    }
    for(int i=0; i<n; i++){
        if(arr[i]/n >1)
            cout<<i<<endl;
    }
    return 0;
}