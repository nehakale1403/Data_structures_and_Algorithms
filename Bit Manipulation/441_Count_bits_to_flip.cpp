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

int convertNum(int x, int y){

    int res = x ^ y;
    return countOnBits(res);
}

int main(){
    int x, y;
    cin>>x>>y;

    cout<<convertNum(x, y);
}