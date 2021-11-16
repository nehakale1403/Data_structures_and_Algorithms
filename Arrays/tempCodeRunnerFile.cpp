#include<bits/stdc++.h>
using namespace std;

int arrFib[1001] = {0};


int fib(int n){

    if(arrFib[n] != 0){
        return arrFib[n];
    }
    
    if(n == 1 || n == 2){
        arrFib[n] = 1;
        return 1;
    }
    
    arrFib[n] = fib(n-1)+fib(n-2);
    return arrFib[n];
}




int minSteps(int targetSum, int n){

    if(targetSum == 0){
        return 0;
    }

    int minCount = INT_MAX;

    for(int i=1; i<n; i++){
        if(arrFib[i] <= targetSum){
            int temp;
            temp =  1 + minSteps(targetSum - arrFib[i], n);
            if(temp != INT_MAX && temp + 1 < minCount)
                minCount = temp;
        }
        
    }

    return minCount;
}

int main(){
    int n;
    cin>>n;

    fib(n);

    // for(int i=0; i<n; i++)
    //     cout<<arrFib[i]<<" ";
    cout<<minSteps(n, n);
}