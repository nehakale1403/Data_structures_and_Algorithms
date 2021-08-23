#include<bits/stdc++.h>
using namespace std;

int minimize(int a[], int b[], int n){

    sort(a, a+n);
    sort(b, b+n);

    long long sum=0;
    for(int i=0; i<n; i++){
        sum += abs(a[i] - b[i]);
    }    
    return sum;
}

int main(){
    
    int n;
    cin>>n;

    int a[n];
    int b[n];

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    cout<<minimize(a, b, n);

}