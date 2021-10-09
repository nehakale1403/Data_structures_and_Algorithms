#include<bits/stdc++.h>
using namespace std;

string sumstring(string s1, string s2){
    if(s1.length() > s2.length())
        swap(s1, s2);
    
    string res = "";

    int n1 = s1.length();
    int n2 = s2.length();

    int diff = n2-n1;
    int carry = 0;

    for(int i = n1-1; i>=0; i--){
        int sum = (s1[i]-'0') + (s2[i+diff] - '0') + carry;
        res.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if(carry){
        res.push_back(carry+ '0');
    }

    reverse(res.begin(), res.end());

    return res;
}

string solve(int arr[], int n){

    sort(arr, arr+n);
    string num1, num2;

    for(int i=0; i<n; i++){
        if(i%2 == 0){
            int num = arr[i];
            if(arr[i] == 0 && num1.length() == 0)
                continue;
            num1 += to_string(num);
        }else{
            int num = arr[i];
            if(arr[i] == 0 && num2.length() == 0)
                continue;
            num2 += to_string(num);
        }
    }

    return sumstring(num1, num2);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<solve(arr,n);
}