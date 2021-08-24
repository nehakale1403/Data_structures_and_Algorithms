#include<bits/stdc++.h>
using namespace std;

int pageFaults(int arr[], int n, int c){

    int count=0;
    vector<int> v;
    int i;

    for(int i=0; i<n; i++){
        auto it = find(v.begin(), v.end(), arr[i]);

        if(it == v.end()){
            if(v.size() == c){
                v.erase(v.begin());
            }
            v.push_back(arr[i]);
            count++;
        }else{
            v.erase(it);
            v.push_back(arr[i]);
        }
    }    
    return count;
}

int main(){
    
    int n;
    cin>>n;
    int c;
    cin>>c;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<pageFaults(arr, n, c);

}