#include<bits/stdc++.h>
using namespace std;

int main(){

    int c, r;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }

    int min = INT_MAX, max = INT_MIN;
    for(int i=0; i<r; i++){
        if(arr[i][0] < min)
            min = arr[i][0];

        if(arr[i][c-1] > max)
            max = arr[i][c-1]; 
    }
    int desired = (r*c+1)/2;
    while(min<max){
        int mid = min+ (max-min)/2;
        int place=0;

        for(int i=0; i<r; i++)
            place = place + upper_bound(arr[i], arr[i]+c, mid) - arr[i];
        
        if(place<desired)
            min = mid+1;
        else
            max = mid;
    }
    cout<<min;

}