#include<bits/stdc++.h>
using namespace std;

void canSurvive(int s,int n,int m){
    
    if(n<m || ((n*6) < (m*7) && s>6)){
        cout<<"No"<<endl; 
    }else{
        int days = (m * s) / n;
        if(((m*s) % n) != 0)
            days++;
        cout<<"Yes "<<days<<endl;
    }
}

int main(){

    int s, n, m;
    cin>>s>>n>>m;

    canSurvive(s,n,m);
}