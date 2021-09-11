#include<bits/stdc++.h>
using namespace std;

void findNumbers(vector<int> &arr, int sum, vector<vector<int>> &res, vector<int> &r, int i){
    if(sum == 0){
        res.push_back(r);
        return;
    }
    while(i<arr.size() && sum - arr[i] >=0){
        r.push_back(arr[i]);
        findNumbers(arr, sum - arr[i], res, r, i);
        i++;
        r.pop_back();
    }
}

vector<vector<int>> combinationalSum(vector<int> arr, int n, int sum){

    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> r;
    vector<vector<int>> res;
    findNumbers(arr, sum, res, r, 0);

    return res;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int sum;
    cin>>sum;

    vector<vector<int>> res = combinationalSum(arr, n, sum);

    if(res.empty()){
        cout<<"Empty"<<endl;
        return 0;
    }

    for(int i=0; i<res.size(); i++){
        if(res[i].size() > 0){
            cout<<"( ";
            for(int j=0; j<res[i].size(); j++){
                cout<<res[i][j]<<" ";
            }
            cout<<")"<<endl;
        }
    }
}