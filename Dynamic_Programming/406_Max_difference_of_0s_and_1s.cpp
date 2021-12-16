#include<bits/stdc++.h>
using namespace std;

int maxSubstring(string s){

    int arr[s.length()] = {0};

    int i=0;
    while(s[i] == '1'){
        arr[i] = -1;
        i++;
    }

    while(i<s.length()){
        if(s[i] == '0'){
            if(arr[i-1] == -1 || i==0){
                arr[i] = 1;
            }else{
                arr[i] = max(arr[i-1] + 1, 1);
            }
        }else{
            arr[i] = arr[i-1] - 1;
        }
        i++;
    }
    
    int ans = INT_MIN;
    for(int i=0; i<s.length(); i++){
        // cout<<arr[i]<<" ";
        if(ans < arr[i])
            ans = arr[i];
    }

    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<maxSubstring(s);
}