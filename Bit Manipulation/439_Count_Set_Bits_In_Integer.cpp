#include <bits/stdc++.h>
using namespace std;

int countOnBits(int n){
    int count = 0;
       
       while(n != 0)
       {
           int rsbm = n & -n; //rightmost set bit mask
           n = n - rsbm;
           count++;
       }
       return count;
}

int main(){
    
    int n;
    cin>>n;

    cout<<countOnBits(n);
}