#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int count=0;
    for(int i=1; i<n; i++){

        int sq = i*i;
        if(sq<n){
            cout<<sq<<" ";
            count++;
        }else if(sq > n){
            break;
        }
    }
    cout<<"\n"<<count<<endl;
}