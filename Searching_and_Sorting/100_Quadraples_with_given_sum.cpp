#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findQuadraple(int arr[], int n, int target){

    sort(arr, arr+n);
    int sum=0;
    set<vector<int>> ans;

    for(int i=0; i<n-3; i++){
        if(i>0 && arr[i] == arr[i-1]) continue; //skipping the repeating elements
        for(int j=i+1; j<n-1; j++){
            if(j>i+1 && arr[j]== arr[j-1]) continue;
            int left = j+1, right=n-1;

            while(left<right){
                sum = arr[i]+arr[j]+arr[left]+arr[right];
                if(sum>target)
                    right--;
                else if(sum == target){
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(arr[left]);
                    v.push_back(arr[right]);
                    ans.insert(v);
                    left++;
                }else{
                    left++;
                }
                    
            }
        }
    }

    vector<vector<int>> res;
    for(auto it:ans)
        res.push_back(it);

    return res;
    
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int target;
    cin>>target;
    vector<vector<int> > ans = findQuadraple(arr, n, target);

        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
}