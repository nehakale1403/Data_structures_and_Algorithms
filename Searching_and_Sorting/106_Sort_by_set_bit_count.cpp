#include<bits/stdc++.h>
using namespace std;

int countBits(int a){
    int count=0;
    while(a){
        if(a&1)
            count+=1;
        a = a >> 1;
    }
    return count;
}

static bool comparator(int i, int j){

    int count1 = countBits(i);
    int count2 = countBits(j);

    if(count1<=count2)
        return false;
    
    return true;
}

void sortbysetbitcount(int arr[], int n){
    stable_sort(arr, arr+n, comparator);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sortbysetbitcount(arr, n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}