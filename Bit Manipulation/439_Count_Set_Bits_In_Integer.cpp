#include <bits/stdc++.h>
using namespace std;

int countOnBits(int N){
    int count = 0;
       
       while(N>0)
       {
           count++;
           N = N & (N-1);
       }
       return count;
}

int main(){
    
    int n;
    cin>>n;

    countOnBits(n);
}