#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr1[n];
    int arr2[n];
    for(int i=0; i<n; i++) cin>>arr1[i];
    for(int i=0; i<n; i++) cin>>arr2[i];

    int count;
    int m1=-1, m2=-1;
    int i=0, j=0;

    for(count=0; count<=n; count++){

        if(i==n){
            m1 = m2;
            m2 = arr2[0];
            break;
        }else if(j==n){
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        if(arr1[i]<=arr2[j]){
            m1 = m2;
            m2 = arr1[i++];
        }else{
            m1 = m2;
            m2 = arr2[j++];
        }
    }
    cout<<(m1+m2)/2<<endl;
}