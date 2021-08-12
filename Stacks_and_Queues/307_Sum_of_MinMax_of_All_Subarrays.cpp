#include<bits/stdc++.h>
using namespace std;

int sumOfKSubarrays(int arr[], int n, int k){
    int sum=0;
    deque<int> g(k), s(k);

    int i=0;
    for(i=0; i<k; i++){
        while((!s.empty()) && arr[s.back()] >= arr[i])
            s.pop_back();
        
        while((!g.empty()) && arr[g.back()] <= arr[i])
            g.pop_back();

        g.push_back(i);
        s.push_back(i);
    }

    for(; i<n; i++){

        sum += arr[s.front()]+ arr[g.front()];
        while(!s.empty() && s.front() <= i-k)
            s.pop_front();
        while(!g.empty() && g.front() <= i-k)
            g.pop_front();

        while((!s.empty()) && arr[s.back()] >= arr[i])
            s.pop_back();
        while((!g.empty()) && arr[g.back()]<= arr[i])
            g.pop_back();
        
        g.push_back(i);
        s.push_back(i);
    }

    sum += arr[s.front()]+arr[g.front()];

    return sum;
}   

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    cout<<sumOfKSubarrays(arr, n, k);

}