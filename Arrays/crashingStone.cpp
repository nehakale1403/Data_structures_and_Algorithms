#include<bits/stdc++.h>
using namespace std;

int crashingStone(int arr[], int n){
    
    priority_queue<int> heap;

    for(int i=0; i<n; i++){
        heap.push(arr[i]);
    }

    while(n>1){
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        n = n-2;

        if(a == b){
            continue;
        }else{
            heap.push(a-b);
            n +=1;
        }
    }

    if(n== 0)
        return 0;
    else
        return heap.top();

}

int main(){

    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<crashingStone(arr, n);
}