#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int main(){

    int m, n;
    cin>>m>>n;

    m--;
    n--;

    int hor[m];
    int ver[n];

    for(int i=0; i<m; i++) cin>>hor[i];
    for(int i=0; i<n; i++) cin>>ver[i];

    sort(hor, hor+m, comp);
    sort(ver, ver+n, comp);

    int cost=0;
    int hor_blocks=1;
    int ver_blocks=1;

    int i=0, j=0;

    while(i<m && j<n){
        
        if(hor[i] > ver[j]){
            cost += hor[i] * hor_blocks;
            ver_blocks++;
            i++;
        }else{
            cost += ver[j] * ver_blocks;
            hor_blocks++;
            j++;
        }

    }

    while(i<m){
        cost += hor[i] * hor_blocks;
        ver_blocks++;
        i++;
    }

    while(j<n){
        cost += ver[i] * ver_blocks;
        hor_blocks++;
        j++;
    }

    cout<<cost<<endl;
}