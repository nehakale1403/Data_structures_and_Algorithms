#include<bits/stdc++.h>
using namespace std;


map<int,int> m;

int numOfWays(int n, int min){

    int index = (n * 10) + min;
    if(m[index]>0)
        return m[index];

    if(n==0) return 1;  

    if(n < 0) return 0;

    int ways = 0;
    if(min <= 3)
    ways += numOfWays(n-3, 3);
    if(min <= 5)
    ways += numOfWays(n-5, 5);
    if(min <= 10)
    ways += numOfWays(n-10, 10); // from now on elements must be 10 or greater

    return m[index] = ways;
}

int main(){
    
    int n;
    cin>>n;

    cout<<numOfWays(n, 1);
}