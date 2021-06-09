#include<bits/stdc++.h>
using namespace std;

int countSubarray(int arr[], int n){

    int count=0;
    int i=-1;
    int sum=0;
    unordered_map<int, int> map;
    map[0]=1;
    while(i<n-1){
        i++;
        sum+=arr[i];
        if(map.find(sum) != map.end()){

            count+=map[sum];
            map[sum]++;
        }else{
            map[sum]++;
        }
    }
    
    return count;

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<countSubarray(arr, n);
}