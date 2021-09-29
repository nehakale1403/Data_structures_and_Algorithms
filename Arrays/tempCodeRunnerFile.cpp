#include<bits/stdc++.h>
using namespace std;

int getMinDifference(int arr[], int n, int k){
    
    sort(arr, arr+n);

    int ans = arr[n-1] - arr[0];

    int smallest = arr[0]+k;
    int largest = arr[n-1]-k;
    int minimum, maximum;

    for(int i=0; i<n-1; i++){
        cout<<"For: i = "<<i<<endl;
        cout<<"Ans: "<<ans<<endl;
        cout<<smallest<<" "<<largest<<" ";

        minimum = min(smallest, arr[i+1]-k);
        maximum = max(largest, arr[i]+k);
        if(minimum<0)
            continue;
        ans = min(ans, maximum-minimum);
        cout<<endl;
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<getMinDifference(arr, n, k);

}