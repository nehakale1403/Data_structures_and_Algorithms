#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int flag=0;
        for(int i=0; i<n; i++){
            int num=arr[i];
            int rev=0;
            while(num!=0){
                rev = (rev*10) + (num%10);
                num = num/10;
            }
            if(rev!=arr[i]){
                flag = 1;
                break;
            }
                
        }
        if(flag==1)
            cout<<"0";
        else
            cout<<"1";

    }


}