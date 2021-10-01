#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX

void printP(int p[], int n){
    if(p[n] == 1)
        cout<<p[n]<<" "<<n<<" ";
    else{
        printP(p, p[n]-1);
        cout<<p[n]<<" "<<n<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    

    int m; //characters per line
    cin>>m;

    int space[n+1][n+1]; //stores the extra spaces for each and every combination
    int ls[n+1][n+1]; //stores cost for each space
    int c[n+1]; //stores optimal answer
    int p[n+1]; // stores the path or index of optimal solution

    for(int i=1; i<=n; i++){
        space[i][i] = m - a[i];
        for(int j=i+1; j<=n; j++){
            space[i][j] = space[i][j-1] - a[j] -1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(space[i][j]<0){
                ls[i][j] = inf;
            }else if(j==n && space[i][j] >= 0){
                ls[i][j] = 0;
            }else{
                ls[i][j] = space[i][j] * space[i][j];
            }
        } 
    }

    c[0] = 0;
    for(int i=1; i<=n; i++){
        c[i] = inf;
        for(int j=1; j<=i; j++){
            if(c[j-1]!=inf && ls[j][i] != inf && c[j-1] + ls[j][i] < c[i]){
                c[i] = c[j-1] + ls[j][i];
                p[i] = j;
            }
        }
    }

    for(int i=0; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl; 
    printP(p, n);
}
