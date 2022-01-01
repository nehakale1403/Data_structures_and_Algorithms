#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j){
    int s = 0;
    for (int k = i; k <= j; k++)
    s += freq[k];
    return s;
}

int optCost(int freq[], int i, int j){

    if(j<i) return 0;
    if(i == j) return freq[i];

    int freqsum = sum(freq, i, j);

    int min = INT_MAX;


    for(int r = i; r <= j; r++){
        int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
        if(cost < min) min = cost;
    }

    return min + freqsum;
}

int optimalSearchTree(int keys[], int freq[], int n){

    return optCost(freq, 0, n-1);
}

int main(){

    int n;
    cin>>n;

    int keys[n];
    int freq[n];

    for(int i=0; i<n; i++) cin>>keys[i];
    for(int i=0; i<n; i++) cin>>freq[i];

    cout<<optimalSearchTree(keys, freq, n);

}