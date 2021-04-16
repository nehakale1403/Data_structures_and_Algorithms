//method 2.....space complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    int a[n1], b[n2], c[n3];
    for(int i=0; i<n1; i++) cin>>a[i];
    for(int i=0; i<n2; i++) cin>>b[i];
    for(int i=0; i<n3; i++) cin>>c[i];

    vector<int> res;
    
    int i=0, j=0, k=0;
    while(i<n1){
        if(a[i]==b[j] and b[j]==c[k]){
            res.push_back(a[i]);
            i++;
            j++;
            k++;
        }else if(a[i]<b[j]){
            i++;
        }else if(b[j]<c[k]){
            j++;
        }else{
            k++;
        }
        int x=a[i-1];
        int y=b[j-1];
        int z=c[k-1];

        while(a[i]==x) i++;
        while(b[j]==y) j++;
        while(c[k]==z) k++;
    }

    for(int i=0;i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}