#include<bits/stdc++.h>
using namespace std;

int res=0;

int knapsack(int n, int profit[], int wt[], int capacity){

    cout<<capacity<<endl;

    if(capacity == 0 || n == 0) return 0;

    if(capacity >= wt[n-1]){
        return max(profit[n-1] + knapsack(n, profit, wt, capacity - wt[n-1]), knapsack(n-1,profit, wt, capacity));
    }else{
        return knapsack(n-1, profit, wt, capacity);
    }
}

int main(){
    
    int n;
    cin>>n;

    int profit[n];
    int wt[n];

    for(int i=0; i<n; i++) cin>>profit[i];
    for(int i=0; i<n; i++) cin>>wt[i];

    int capacity;
    cin>>capacity;

    cout<<knapsack(n, profit, wt, capacity);

}