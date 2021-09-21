#include<bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[], int subset,
 int k, int n, int curIdx, int limitIdx){

    if(subsetSum[curIdx] == subset){
        if(curIdx == k-2){
            return true;
        }
        return isKPartitionPossibleRec(arr, subsetSum, taken, subset, k, n, curIdx+1, n-1);
    }

    for(int i=limitIdx; i>=0; i--){
        if(taken[i])
            continue;

        int tmp = subsetSum[curIdx] + arr[i];

        if(tmp <= subset){
            taken[i] = true;
            subsetSum[curIdx] += arr[i];

            bool nxt  = isKPartitionPossibleRec(arr, subsetSum, taken, subset, k, n, curIdx, i-1);
            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if(nxt) 
                return true;
        }

    }
    return false;
}

bool isPartitionPsble(int n, int arr[], int k){
    if(k==1){
        
        return true;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    if(k>n || sum%k != 0){
    
        return false;
    }

    int subset = sum / k;
    int subsetSum[k];
    bool taken[n];

    for (int i = 0; i < k; i++)
        subsetSum[i] = 0;
    for (int i = 0; i < n; i++)
        taken[i] = false;
    
    subsetSum[0] = arr[n - 1];
    taken[n - 1] = true;

    return isKPartitionPossibleRec(arr, subsetSum, taken, subset, k, n, 0, n - 1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    int subsetSum[k];

    vector<vector<int>> v;
    
    cout<<isPartitionPsble(n, arr, k);
}