#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int b[], int m){

    int s1=0, s2=0;
    int i=0, j=0;
    int ans=0;
    while(i<n && j<m){
        if(a[i]<b[j])
            s1+=a[i++];
        else if(b[j]<a[i])
            s2+=b[j++];
        else{
            ans = ans + max(s1, s2) + a[i];
            s1=s2=0;
            i++;
            j++;
        }
    }
    while(i<n)
        s1+=a[i++];
    while(j<m)
        s2+=b[j++];

    ans = ans+ max(s1, s2);
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int m;
    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
        cin>>b[i];
    
    cout<<solve(a, n, b, m);
}