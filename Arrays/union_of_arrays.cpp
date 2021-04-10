//union of 2 arrays

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int a[n], b[m];

    unordered_map <int, int> map;

    /*for eg
    1 2 2 3 3 4 5

    map stores:
    1 1 ---value and count
    2 2
    3 2
    4 1
    5 1
    */

    for(int i=0; i<n; i++){
        cin>>a[i];
        map[a[i]]++;
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
        map[b[i]]++;
    }

    cout<<map.size()<<endl;
}