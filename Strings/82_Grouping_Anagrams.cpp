#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &arr){

    unordered_map<string, vector<string>> m;
    int n = arr.size();
    string temp;

    for(int i=0; i<n; i++){
        temp = arr[i];
        sort(arr[i].begin(), arr[i].end());
        m[arr[i]].push_back(temp);
    }

    vector<vector<string>> result;
    
    for(auto i=m.begin(); i!=m.end(); i++){
        result.push_back(i->second);

    }
        
    
    return result;

}

int main(){

    int n;
    cin>>n;
    vector<string> arr(n);

    for(int i=0; i<n; i++){
        string t;
        cin>>t;
        arr.push_back(t);
    }

    
    vector<vector<string>> res = groupAnagrams(arr);

    for( auto string_vec : res ){
        for( auto s : string_vec ){
            cout << s<<" ";
        }     
        cout<<endl;
    }
        

}