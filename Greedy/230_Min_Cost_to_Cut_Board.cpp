#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin>>m>>n;
    m--;
    n--;

    int x[m];
    int y[n];
    for(int i=0; i<m; i++) cin>>x[i];
    for(int i=0; i<n; i++) cin>>y[i];

    sort(x, x+m, greater<int>());
    sort(y, y+n, greater<int>());

    int horizontal=1;
    int vertical=1;
    int answer = 0;
    int i=0, j=0;

    while(i<m && j<n){
        if(x[i]>y[j]){
            answer += x[i]*vertical;
            horizontal++;
            i++;
        }else{
            answer += y[j]*horizontal;
            vertical++;
            j++;
        }
    }

    while(i<m){
        answer += x[i]*vertical;
        i++;
    }
    while(j<n){
        answer += y[j]*horizontal;
    }

    cout<<answer;
}