#include <bits/stdc++.h>
using namespace std;

struct Job{
    int start, end, profit;
};

bool comp(Job a, Job b){

    return a.end < b.end;
}

int latestNonConflict(Job arr[], int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (arr[j].end <= arr[i-1].start)
            return j;
    }
    return -1;
}

int maxProfit(Job arr[], int n){

    if(n == 1) return arr[n-1].profit;

    int incl = arr[n-1].profit;
    int i = latestNonConflict(arr,n);
    if(i != -1)
        incl += maxProfit(arr, i+1);
    
    int excl = maxProfit(arr, n-1);

    return max(incl, excl);

}


int main(){
    
    int n;
    cin>>n;
    
    Job arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }

    sort(arr, arr + n, comp);

    cout<<maxProfit(arr, n);
}