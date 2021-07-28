#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int maxR = arr[0];
    int step = arr[0];
    int jumps = 1;

    if(n==1)
        cout<<0;
    else if(arr[0]==0)
        cout<<-1;
    else{
        for(int i=1; i<n; i++){
            if(i==n-1)
                cout<<jumps;
            maxR = max(maxR, arr[i]+i);
            step--;
            if(step==0){
                jumps++;
                if(i>=maxR){
                    cout<<-1;
                }
                step = maxR-1;
            }
        }
        
    }
}