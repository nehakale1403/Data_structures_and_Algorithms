#include<bits/stdc++.h>
using namespace std;

int main(){

    int m, n;
    cin>>m>>n;

    int arr1[m], arr2[n];
    for(int i=0; i<m; i++)
        cin>>arr1[i];
    for(int i=0; i<n;i++)
        cin>>arr2[i];

    int k_req;
    cin>>k_req;

    int i=0, j=0, k=0;

    while(i<m && j<n){

        if(arr1[i] < arr2[j]){
            k++;
            if(k==k_req){
                cout<<arr1[i];
                break;
            }
            i++;   
              
        }else{

            k++;
            if(k==k_req){
                cout<<arr2[j];
                break;
            }
            j++;   
        }   
    }
    while(i < m)
    {
        k++;
        if(k == k_req)
            return arr1[i];
        i++;
    }
 
    while(j < n)
    {
        k++;
        if(k == k_req)
            return arr2[j];
        j++;
    }
}