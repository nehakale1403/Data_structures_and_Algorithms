#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    char arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int i=0, j=n-1;
    int flag=0;
    while(i<j){
        if(arr[i]!=arr[j]){
            flag=1;
            break;
        }
        i++;
        j--;
    }

    if(flag==0)
        cout<<1;
    else
        cout<<0;
}