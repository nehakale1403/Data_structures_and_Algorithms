#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    bool arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int maxval = INT_MIN;
    for(int a=0; a<n-1; a++)
        for(int b=0; b<n-1; b++)
            for(int d=a+1; d<n; d++)
                for(int e=b+1; e<n; e++)
                    if(maxval < (arr[d][e]-arr[a][b]))
                        maxval = arr[d][e]-arr[a][b];

    cout<<maxval;
}