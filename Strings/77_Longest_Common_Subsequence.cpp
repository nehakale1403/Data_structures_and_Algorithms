#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int n, int m){

    int arr[n+1][m+1];
    int i, j;

    for(i=0; i<=n; i++)
        arr[i][0] = 0;

    for(i=0; i<=m; i++)
        arr[0][i] = 0;

    
    for(int i=1; i<=n; i++){
        for(int j=1;j<=m; j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = 1+arr[i-1][j-1];
            }else{
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
    }

    return arr[n][m];

}
int main(){

    string a, b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    cout<<LCS(a, b, n, m);

}