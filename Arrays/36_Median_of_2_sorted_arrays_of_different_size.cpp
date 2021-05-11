#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1>>n2;

    int arr1[n1], arr2[n2];
    for(int i=0; i<n1; i++) cin>>arr1[i];
    for(int i=0; i<n2; i++) cin>>arr2[i];

    int m1=-1, m2=-1;
    int i=0, j=0;
    int count;
    if((n1+n2)%2 == 1){

        for(count=0; count<=(n1+n2)/2; count++){
    
            if(i!=n1 && j!=n2){
                m1 = (arr1[i]>arr2[j]) ? arr2[j++] : arr1[i++];
            }else if(i<n1){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
            
        }
        cout<<m1<<endl;

    }else{
        
        for(count=0; count<=(n1+n2)/2; count++){
            m2 = m1;
            if(i!=n1 && j!=n2){
                m1 = (arr1[i]>arr2[j]) ? arr2[j++] : arr1[i++];
            }else if(i<n1){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
        }
        cout<<(m1+m2)/2;

    }
    
}