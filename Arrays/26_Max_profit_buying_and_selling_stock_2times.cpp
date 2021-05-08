#include<bits/stdc++.h>
using namespace std;

void maxProfit(int price[], int n){

    int profit[n];
    for(int i=0; i<n; i++)
        profit[i]=0;

    int max_price=price[n-1];
    for(int i=n-2; i>=0; i--){
        if(price[i]>max_price)
            max_price = price[i];
        
        profit[i] = max(profit[i+1], max_price - price[i]);
    }

    int min_price = price[0];
    for(int i=1; i<n;i++){
        if(price[i]<min_price)
            min_price = price[i];

        profit[i] = max(profit[i-1], profit[i]+(price[i] - min_price));
    }

    cout<<profit[n-1];
}

int main(){
    int n;
    cin>>n;

    int price[n];
    for(int i=0; i<n; i++) cin>>price[i];

    maxProfit(price, n);
    
}

//METHOD 2 IS OF DYNAMIC PROGRAMMING
//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/