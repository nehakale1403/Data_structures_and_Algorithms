// https://www.youtube.com/watch?v=ju8vrEAsa3Q

//permutation and combination problem

#include<bits/stdc++.h>
using namespace std;

int paintFence(int n, int k){
    long same = k*1;
    long diff = k * (k-1);
    int total = same + diff;
    
    for(int i=3; i<=n; i++){
        same = diff * 1;
        diff = total * (k-1);
        total = same + diff;
    }

    return total;

}

int main(){
    int n, k;
    cin>>n>>k;

    cout<<paintFence(n, k);
}