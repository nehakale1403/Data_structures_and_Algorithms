#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int n){
    int count=0, f=5, temp = mid;

    while(f<=temp){
        count+= temp/f;
        f = f*5;
    }
    return (count>=n);
}

int findnum(int n){
    if(n==1)
        return 5;
    
    int low = 0;
    int high = 5*n;

    while(low<high){
        int mid = (low+high)/2;

        if(check(mid, n))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main(){

    int n;
    cin>>n;

    cout<<findnum(n);
}