#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int i=0;
    int j=n-1;

    while(i<=j){
        
        if(a[i]<0 && a[j]>0){
            swap(a[i], a[j]);
            i++;
            j--;
        }else if(a[i]>0 && a[j]<0){
            i++;
            j--;
        }else if(a[i]>0){
            i++;
        }else if(a[j]<0){
            j--;
        }

        
    }
    
    
    if(i==0 || i==n){
        for(int p=0; p<n; p++) cout<<a[p]<<" ";
    }else{
        int k=0;
        while(i<n and k<n){
            swap(a[k], a[i]);
            k+=2;
            i++;
        }
    }
    
   

    for(int i=0; i<n; i++)
        cout<<a[i];
}