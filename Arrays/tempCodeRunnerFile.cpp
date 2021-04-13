#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int a[n], b[m];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    for(int i=m-1; i>0; i--){
        int j;
        int last = a[n-1];

        for(j=n-2; j>=0 && a[j] > b[i]; j--){
            a[j+1] = a[j];

        }
        
        if(j!=n-2 || last>b[i]){
            a[j+1] = b[i];
            b[i] = last;
        }        
    }

    for(int i=0; i<n; i++){
        cout<<a[i];
    }   
    for(int i=0; i<m; i++){
        cout<<b[i];
    }
}