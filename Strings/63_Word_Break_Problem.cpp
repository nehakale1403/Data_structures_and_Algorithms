#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int solve(string s, vector<string> &b){

    
    int n = s.length();
    if(n == 0)
        return 1;
    if(dp[s]!=0)
        return dp[s];
    
    for(int i=1; i<=n; i++){
        int flag=0;
        string ss = s.substr(0, i);
        for(int j=0; j<b.size(); j++){
            if(ss.compare(b[j]) == 0){
                flag = 1;
                break;
            }
        }
        if(flag==1 && (solve(s.substr(i, n-i), b)== 1))
            return dp[s]=1;
    }
    return dp[s] = -1;
}

int main(){

    int n;
    cin>>n;

    vector<string> B(n);
    string A;

    
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        B.push_back(temp);
    }
    cin>>A;

    if(solve(A, B) == 1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}